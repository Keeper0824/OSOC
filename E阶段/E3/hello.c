#include <stdio.h>

int divide(int a, int b)
{
    return a / b;
}

int main(void)
{
    int a = 13;
    int b = 0;

    printf("Hello World\n");
    printf("%d / %d = %d\n", a, b, divide(a, b));

    return 0;
}
