#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random valid password for the program 101-crackme.
 *
 * Return: Always 0.
 */
int main(void)
{
    int sum = 0;
    char c;

    srand(time(NULL));

    while (sum <= 2645)
    {
        c = rand() % 128;
        if ((sum + c) > 2772)
            break;
        sum += c;
        putchar(c);
    }

    putchar(2772 - sum);
    putchar('\n'); // Ensure newline at the end of output

    return (0);
}

