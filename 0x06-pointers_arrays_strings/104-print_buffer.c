#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of the buffer
 */
void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		for (j = 0; j < 10; j++)
		{
			if ((j + i) < size)
				printf("%02x", *(b + j + i));
			else
				printf("  ");
			if (j % 2)
				printf(" ");
		}
		for (j = 0; j < 10; j++)
		{
			if ((j + i) < size)
			{
				int c = *(b + j + i);

				if (c < 32 || c > 126)
					c = '.';
				printf("%c", c);
			}
		}
		printf("\n");
	}
}
