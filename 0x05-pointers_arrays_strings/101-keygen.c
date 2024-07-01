#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for the program 101-crackme.
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

	return (0);
}
