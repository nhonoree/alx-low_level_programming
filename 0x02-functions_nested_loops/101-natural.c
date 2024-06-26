#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always returns 0 (SUCCESS)
 */
int main(void)
{
	/* Initialize variables */
	int limit = 1024;
	int sum = 0;

	/* Iterate through numbers below limit */
	for (int i = 1; i < limit; i++)
	{
		/* Check if the number is a multiple of 3 or 5 */
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i; /* Add to the sum if it's a multiple */
		}
	}

	/* Output the result */
	printf("The sum of all multiples of 3 or 5 below %d is: %d\n", limit, sum);

	return (0); /* Return SUCCESS */
}
