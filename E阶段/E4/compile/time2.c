#include <stdio.h>

int main(int argc, char *argv[])
{
    long long n = 2000000000LL;

    volatile long long sum = 0;

    for (long long i = 1; i <= n; i++)
        sum += i;

    printf("%lld\n", sum);
    return 0;
}
