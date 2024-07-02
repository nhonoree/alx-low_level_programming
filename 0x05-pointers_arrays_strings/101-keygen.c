#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

/**
 * main - generates random valid passwords for the program 101-crackme
 *
 * Return: Always 0.
 */
int main(void)
{
    int i;
    char password[PASSWORD_LENGTH + 1];

    /* Seed the random number generator */
    srand(time(NULL));

    /* Generate a random password */
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        /* Generate a random character (printable ASCII characters) */
        password[i] = rand() % 94 + 33; /* 33 to 126 are printable characters */
    }

    /* Null-terminate the password string */
    password[PASSWORD_LENGTH] = '\0';

    /* Print the generated password */
    printf("%s\n", password);

    return (0);
}
