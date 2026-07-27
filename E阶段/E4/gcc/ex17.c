#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct Address {
    int id;
    int set;
    char *name;
    char *email;
    char *city;
char *phone;
};

struct Database {
    int max_data;
    int max_rows;
    struct Address *rows;
};

struct Connection {
    FILE *file;
    struct Database *db;
};

struct Connection;
void Database_close(struct Connection *conn);
static struct Connection *conn = NULL;
void die(struct Connection *conn, const char *message);
void Address_print(struct Address *addr);

const char *Address_field(
    struct Connection *conn,
    struct Address *addr,
    const char *field)
{
    if(strcmp(field, "name") == 0) {
        return addr->name;
    }

    if(strcmp(field, "email") == 0) {
        return addr->email;
    }

    if(strcmp(field, "city") == 0) {
        return addr->city;
    }

    if(strcmp(field, "phone") == 0) {
        return addr->phone;
    }

    errno = 0;
    die(conn, "Unknown search field");
}


void Database_find(
    struct Connection *conn,
    const char *field,
    const char *query)
{
    int found = 0;

    for(int i = 0; i < conn->db->max_rows; i++) {
        struct Address *addr = &conn->db->rows[i];

        if(!addr->set) {
            continue;
        }

        const char *value = Address_field(conn, addr, field);

        if(strstr(value, query) != NULL) {
            Address_print(addr);
            found = 1;
        }
    }

    if(!found) {
        errno = 0;
        die(conn, "No matching records");
    }
}

void die(struct Connection *conn, const char *message)
{
    Database_close(conn);

    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
printf("%d %s %s %s %s\n",
       addr->id,
       addr->name,
       addr->email,
       addr->city,
       addr->phone);
}

void Database_load(struct Connection *conn)
{
    struct Database *db = conn->db;

    if(fread(&db->max_data, sizeof(int), 1, conn->file) != 1)
        die(conn, "Failed to read max_data");

    if(fread(&db->max_rows, sizeof(int), 1, conn->file) != 1)
        die(conn, "Failed to read max_rows");

    if(db->max_data <= 1 || db->max_rows <= 0) {
        errno = 0;
        die(conn, "Invalid database file");
    }

    db->rows = calloc(db->max_rows, sizeof(struct Address));
    if(!db->rows)
        die(conn, "Memory error");

    for(int i = 0; i < db->max_rows; i++) {
        struct Address *addr = &db->rows[i];

        addr->name = calloc(db->max_data, 1);
        addr->email = calloc(db->max_data, 1);
        addr->city = calloc(db->max_data, 1);
        addr->phone = calloc(db->max_data, 1);

        if(!addr->name || !addr->email ||
           !addr->city || !addr->phone) {
            die(conn, "Memory error");
        }

        if(fread(&addr->id, sizeof(int), 1, conn->file) != 1)
            die(conn, "Failed to read id");

        if(fread(&addr->set, sizeof(int), 1, conn->file) != 1)
            die(conn, "Failed to read set");

        if(fread(addr->name, db->max_data, 1, conn->file) != 1)
            die(conn, "Failed to read name");

        if(fread(addr->email, db->max_data, 1, conn->file) != 1)
            die(conn, "Failed to read email");

        if(fread(addr->city, db->max_data, 1, conn->file) != 1)
            die(conn, "Failed to read city");

        if(fread(addr->phone, db->max_data, 1, conn->file) != 1)
            die(conn, "Failed to read phone");

        addr->name[db->max_data - 1] = '\0';
        addr->email[db->max_data - 1] = '\0';
        addr->city[db->max_data - 1] = '\0';
        addr->phone[db->max_data - 1] = '\0';
    }
}

struct Connection *Database_open(const char *filename, char mode)
{
struct Connection *conn = calloc(1, sizeof(struct Connection));
if(!conn) die(NULL, "Memory error");

conn->db = calloc(1, sizeof(struct Database));
if(!conn->db) die(conn, "Memory error");

if(mode == 'c') {
    conn->file = fopen(filename, "w+b");
} else {
    conn->file = fopen(filename, "r+b");

    if(conn->file) {
        Database_load(conn);
    }
}
    if(!conn->file) die(conn,"Failed to open the file");

    return conn;
}

void Database_close(struct Connection *conn)
{
    if(!conn)
        return;

    if(conn->file)
        fclose(conn->file);

    if(conn->db) {
        if(conn->db->rows) {
            for(int i = 0; i < conn->db->max_rows; i++) {
                free(conn->db->rows[i].name);
                free(conn->db->rows[i].email);
                free(conn->db->rows[i].city);
                free(conn->db->rows[i].phone);
            }

            free(conn->db->rows);
        }

        free(conn->db);
    }

    free(conn);
}

void Database_write(struct Connection *conn)
{
    struct Database *db = conn->db;

    rewind(conn->file);

    if(fwrite(&db->max_data, sizeof(int), 1, conn->file) != 1)
        die(conn, "Failed to write max_data");

    if(fwrite(&db->max_rows, sizeof(int), 1, conn->file) != 1)
        die(conn, "Failed to write max_rows");

    for(int i = 0; i < db->max_rows; i++) {
        struct Address *addr = &db->rows[i];

        if(fwrite(&addr->id, sizeof(int), 1, conn->file) != 1)
            die(conn, "Failed to write id");

        if(fwrite(&addr->set, sizeof(int), 1, conn->file) != 1)
            die(conn, "Failed to write set");

        if(fwrite(addr->name, db->max_data, 1, conn->file) != 1)
            die(conn, "Failed to write name");

        if(fwrite(addr->email, db->max_data, 1, conn->file) != 1)
            die(conn, "Failed to write email");

        if(fwrite(addr->city, db->max_data, 1, conn->file) != 1)
            die(conn, "Failed to write city");

        if(fwrite(addr->phone, db->max_data, 1, conn->file) != 1)
            die(conn, "Failed to write phone");
    }

    if(fflush(conn->file) != 0)
        die(conn, "Cannot flush database");
}

void Database_create(struct Connection *conn)
{
    conn->db->max_data = 512;
    conn->db->max_rows = 100;

    conn->db->rows = calloc(
        conn->db->max_rows,
        sizeof(struct Address)
    );

    if(!conn->db->rows)
        die(conn, "Memory error");

    for(int i = 0; i < conn->db->max_rows; i++) {
        struct Address *addr = &conn->db->rows[i];

        addr->id = i;
        addr->set = 0;

        addr->name = calloc(conn->db->max_data, 1);
        addr->email = calloc(conn->db->max_data, 1);
        addr->city = calloc(conn->db->max_data, 1);
        addr->phone = calloc(conn->db->max_data, 1);

        if(!addr->name || !addr->email ||
           !addr->city || !addr->phone) {
            die(conn, "Memory error");
        }
    }
}

void Database_set(
    struct Connection *conn,
    int id,
    const char *name,
    const char *email,
    const char *city,
    const char *phone)
{
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die(conn,"Already set, delete it first");

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, conn->db->max_data - 1);
    addr->name[conn->db->max_data - 1] = '\0';


    // demonstrate the strncpy bug
    if(!res) die(conn,"Name copy failed");
    res = strncpy(addr->email, email, conn->db->max_data - 1);
    addr->email[conn->db->max_data - 1] = '\0';
    if(!res) die(conn,"Email copy failed");
    
    strncpy(addr->city, city, conn->db->max_data - 1);
    addr->city[conn->db->max_data - 1] = '\0';
    strncpy(addr->phone, phone, conn->db->max_data - 1);
    addr->phone[conn->db->max_data - 1] = '\0';
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die(conn,"ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    addr->set = 0;
    addr->name[0] = '\0';
    addr->email[0] = '\0';
    addr->city[0] = '\0';
    addr->phone[0] = '\0';
}
void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < db->max_rows; i++){
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3) die(NULL,"USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    conn = Database_open(filename, action);
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);
    if(action!='c'&&(id < 0 ||id >= conn->db->max_rows)) {
    die(conn, "There's not that many records.");
    }

    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if(argc != 4) die(conn,"Need an id to get");

            Database_get(conn, id);
            break;

        case 's':
	    if(argc != 8)
    		die(conn, "Need id, name, email, city, phone to set");

            Database_set(
    conn,
    id,
    argv[4],
    argv[5],
    argv[6],
    argv[7]
);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die(conn,"Need id to delete");

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            die(conn,"Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }

    Database_close(conn);

    return 0;
}
