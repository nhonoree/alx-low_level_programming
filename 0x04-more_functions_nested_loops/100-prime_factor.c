#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    long num = 612852475143;
    long max_prime = -1;
    long i;

    while (num % 2 == 0)
    {
        max_prime = 2;
        num /= 2;
    }

    for (i = 3; i <= sqrt(num); i += 2)
    {
        while (num % i == 0)
        {
            max_prime = i;
            num /= i;
        }
    }

    if (num > 2)
        max_prime = num;

    printf("%ld\n", max_prime);

    return (0);
}

