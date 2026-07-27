#include <stdio.h>

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES,
    BLACK_EYES, OTHER_EYES
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

size_t scan_word(char *buffer, size_t size)
{
    if(buffer == NULL || size == 0)
        return 0;

    size_t index = 0;
    char ch;

    buffer[0] = '\0';

    /* 第一个字符前允许有空白 */
    if(scanf(" %c", &ch) != 1)
        return 0;

    while(!isspace((unsigned char)ch)) {
        if(index + 1 < size) {
            buffer[index++] = ch;
        }

        if(scanf("%c", &ch) != 1)
            break;
    }

    buffer[index] = '\0';
    return index;
}
int main(int argc, char *argv[])
{
    Person you = {.age = 0};
    int i = 0;
    char *in = NULL;

    printf("What's your First Name? ");
    //in = fgets(you.first_name, MAX_DATA-1, stdin);
    //fscanf(stdin, "%50s", you.first_name);
    scan_word(you.first_name,sizeof(you.first_name));

    printf("What's your Last Name? ");
    //in = fgets(you.last_name, MAX_DATA-1, stdin);
    scan_word(you.last_name,sizeof(you.last_name));
    printf("How old are you? ");
    //int rc = fscanf(stdin, "%d", &you.age);
    int rc = scanf("%d", &you.age);


    printf("What color are your eyes:\n");
    for(i = 0; i <= OTHER_EYES; i++) {
        printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    //rc = fscanf(stdin, "%d", &eyes);
    rc = scanf("%d", &you.age);


    you.eyes = eyes - 1;

    printf("How much do you make an hour? ");
    rc = fscanf(stdin, "%f", &you.income);

    printf("----- RESULTS -----\n");

    printf("First Name: %s", you.first_name);
    printf("Last Name: %s", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);

    return 0;
error:

    return -1;
}
