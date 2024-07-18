#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _isdigit - Checks if a string contains only digits.
 * @s: The string to check.
 *
 * Return: 1 if the string contains only digits, otherwise 0.
 */
int _isdigit(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string to check.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
    int len = 0;

    while (*s++)
        len++;
    return (len);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of arguments.
 * @argv: The arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    char *num1, *num2;
    int len1, len2, len, i, j, carry, digit1, digit2, *result;

    if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
    {
        printf("Error\n");
        exit(98);
    }

    num1 = argv[1];
    num2 = argv[2];
    len1 = _strlen(num1);
    len2 = _strlen(num2);
    len = len1 + len2;
