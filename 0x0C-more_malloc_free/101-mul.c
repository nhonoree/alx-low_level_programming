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
 * multiply - Multiplies two positive numbers and prints the result.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 * @len1: Length of the first number.
 * @len2: Length of the second number.
 */
void multiply(char *num1, char *num2, int len1, int len2)
{
	int len, i, j, carry, digit1, digit2, *result;

	len = len1 + len2;
	result = malloc(sizeof(int) * len);
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		_putchar('0');

	for (; i < len; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
	free(result);
}

/**
 * main - Multiplies two positive numbers and prints the result.
 * @argc: The number of arguments.
 * @argv: The arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	multiply(argv[1], argv[2], _strlen(argv[1]), _strlen(argv[2]));
	return (0);
}
