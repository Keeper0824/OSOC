#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES,
    GREEN_EYES,
    BROWN_EYES,
    BLACK_EYES,
    OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;


int read_line(char *buffer, size_t size)
{
    if(buffer == NULL || size == 0)
        return 0;

    buffer[0] = '\0';

    if(fgets(buffer, (int)size, stdin) == NULL)
        return 0;

    char *newline = strchr(buffer, '\n');

    if(newline != NULL) {
        *newline = '\0';
    } else {
        int ch;

        while((ch = getchar()) != '\n' && ch != EOF) {
        }
    }

    return 1;
}

int contains_whitespace(const char *text)
{
    while(*text != '\0') {
        if(isspace((unsigned char)*text))
            return 1;

        text++;
    }

    return 0;
}

int read_name(const char *prompt, char *name, size_t size)
{
    printf("%s", prompt);

    if(!read_line(name, size))
        return 0;

    if(name[0] == '\0') {
        fprintf(stderr, "Name cannot be empty.\n");
        return 0;
    }

    if(contains_whitespace(name)) {
        fprintf(stderr, "Name cannot contain whitespace.\n");
        return 0;
    }

    return 1;
}

int parse_int(const char *text, int *result)
{
    char *end = NULL;

    errno = 0;
    long value = strtol(text, &end, 10);

    if(errno != 0 || end == text || *end != '\0')
        return 0;

    *result = (int)value;
    return 1;
}

int parse_float(const char *text, float *result)
{
    char *end = NULL;

    errno = 0;
    float value = strtof(text, &end);

    if(errno != 0 || end == text || *end != '\0')
        return 0;

    *result = value;
    return 1;
}

int main(void)
{
    Person you = {0};
    char input[MAX_DATA];

    if(!read_name("What's your First Name? ",
                  you.first_name,
                  sizeof(you.first_name))) {
        return 1;
    }

    if(!read_name("What's your Last Name? ",
                  you.last_name,
                  sizeof(you.last_name))) {
        return 1;
    }

    printf("How old are you? ");

    if(!read_line(input, sizeof(input)) ||
       !parse_int(input, &you.age) ||
       you.age < 0) {
        fprintf(stderr, "Invalid age.\n");
        return 1;
    }

    printf("What color are your eyes:\n");

    for(int i = 0; i <= OTHER_EYES; i++) {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }

    printf("> ");

    int eyes = 0;

    if(!read_line(input, sizeof(input)) ||
       !parse_int(input, &eyes) ||
       eyes < 1 || eyes > OTHER_EYES + 1) {
        fprintf(stderr, "Invalid eye color.\n");
        return 1;
    }

    you.eyes = (EyeColor)(eyes - 1);

    printf("How much do you make an hour? ");

    if(!read_line(input, sizeof(input)) ||
       !parse_float(input, &you.income)) {
        fprintf(stderr, "Invalid income.\n");
        return 1;
    }

    printf("----- RESULTS -----\n");
    printf("First Name: %s\n", you.first_name);
    printf("Last Name: %s\n", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %.2f\n", you.income);

    return 0;
}
