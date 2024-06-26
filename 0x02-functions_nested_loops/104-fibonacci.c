#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always returns 0 (SUCCESS)
 */
int main(void)
{
	int count;
	unsigned long fib1_high = 0, fib1_low = 1;
	unsigned long fib2_high = 0, fib2_low = 2;
	unsigned long next_high, next_low;
	unsigned long max = 1000000000;  /* To handle overflow */

	printf("%lu, %lu", fib1_low, fib2_low);

	for (count = 2; count < 98; count++)
	{
		next_low = fib1_low + fib2_low;
		next_high = fib1_high + fib2_high + (next_low / max);
		next_low = next_low % max;

		printf(", %lu", next_high > 0 ? next_high : next_low);
		if (next_high > 0)
		{
			printf("%09lu", next_low);
		}

		fib1_low = fib2_low;
		fib1_high = fib2_high;
		fib2_low = next_low;
		fib2_high = next_high;
	}

	printf("\n");

	return (0);  /* Return SUCCESS */
}
