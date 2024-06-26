#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always returns 0 (SUCCESS)
 */
int main(void)
{
	unsigned long fib1 = 1, fib2 = 2, next_fib;
	unsigned long sum = 0;

	/* Check the first two Fibonacci numbers */
	if (fib1 % 2 == 0)
	{
		sum += fib1;
	}
	if (fib2 % 2 == 0)
	{
		sum += fib2;
	}

	/* Generate Fibonacci numbers and sum the even-valued terms */
	while (fib2 <= 4000000)
	{
		next_fib = fib1 + fib2;
		fib1 = fib2;
		fib2 = next_fib;

		if (next_fib % 2 == 0 && next_fib <= 4000000)
		{
			sum += next_fib;
		}
	}

	/* Print the result */
	printf("%lu\n", sum);

	return (0);  /* Return SUCCESS */
}
