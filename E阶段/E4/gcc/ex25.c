/** WARNING: This code is fresh and potentially isn't correct yet. */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#define MAX_DATA 100

int read_string(char **out_string, int max_buffer)
{
    *out_string = calloc(1, max_buffer + 1);

    char *result = fgets(*out_string, max_buffer, stdin);
    char *newline = strchr(*out_string, '\n');

    if(newline != NULL) {
        *newline = '\0';
    } else {
        int ch;

        while((ch = fgetc(stdin)) != '\n' && ch != EOF) {
        }
    }
    return 0;

}

int read_int(int *out_int)
{
    char *input = NULL;
    int rc = read_string(&input, MAX_DATA);

    *out_int = atoi(input);

    free(input);
    return 0;
}

int w_string(const char *string)
{
    if(string == NULL)
        return -1;

    return fputs(string, stdout) == EOF ? -1 : 0;
}

int w_int(int value)
{
    char buffer[32];

    int length = snprintf(
        buffer,
        sizeof(buffer),
        "%d",
        value
    );

    if(length < 0 || length >= (int)sizeof(buffer))
        return -1;

    return w_string(buffer);
}

int read_scan(const char *fmt, ...)
{
    int i = 0;
    int rc = 0;
    int *out_int = NULL;
    char *out_char = NULL;
    char **out_string = NULL;
    int max_buffer = 0;

    va_list argp;
    va_start(argp, fmt);

    for(i = 0; fmt[i] != '\0'; i++) {
        if(fmt[i] == '%') {
            i++;
            switch(fmt[i]) {
                case '\0':
                    break;

                case 'd':
                    out_int = va_arg(argp, int *);
                    rc = read_int(out_int);
                    break;

                case 'c':
                    out_char = va_arg(argp, char *);
                    *out_char = fgetc(stdin);
                    break;

                case 's':
                    max_buffer = va_arg(argp, int);
                    out_string = va_arg(argp, char **);
                    rc = read_string(out_string, max_buffer);
                    break;

                default:
            }
        } else {
            fgetc(stdin);
        }

    }

    va_end(argp);
    return 0;
}

int print(const char *fmt, ...)
{
    if(fmt == NULL)
        return -1;

    int status = 0;
    va_list argp;

    va_start(argp, fmt);

    for(int i = 0; fmt[i] != '\0'; i++) {
        if(fmt[i] != '%') {
            if(fputc(fmt[i], stdout) == EOF) {
                status = -1;
                break;
            }

            continue;
        }

        i++;

        if(fmt[i] == '\0') {
            status = -1;
            break;
        }

        switch(fmt[i]) {
            case 'd': {
                int value = va_arg(argp, int);

                if(w_int(value) != 0)
                    status = -1;

                break;
            }

            case 'c': {
                int value = va_arg(argp, int);

                if(fputc(value, stdout) == EOF)
                    status = -1;

                break;
            }

            case 's': {
                char *value = va_arg(argp, char *);

                if(w_string(value) != 0)
                    status = -1;

                break;
            }

            case '%':
                if(fputc('%', stdout) == EOF)
                    status = -1;
                break;

            default:
                status = -1;
                break;
        }

        if(status != 0)
            break;
    }

    va_end(argp);
    return status;
}

int main(int argc, char *argv[])
{
    char *first_name = NULL;
    char initial = ' ';
    char *last_name = NULL;
    int age = 0;

    printf("What's your first name? ");
    int rc = read_scan("%s", MAX_DATA, &first_name);

    printf("What's your initial? ");
    rc = read_scan("%c\n", &initial);

    printf("What's your last name? ");
    rc = read_scan("%s", MAX_DATA, &last_name);

    printf("How old are you? ");
    rc = read_scan("%d", &age);

print("---- RESULTS ----\n");
print("First Name: %s\n", first_name);
print("Initial: '%c'\n", initial);
print("Last Name: %s\n", last_name);
print("Age: %d\n", age);

    free(first_name);
    free(last_name);
    return 0;
}
