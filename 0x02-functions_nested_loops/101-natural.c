#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always returns 0 (SUCCESS)
 */
int main(void)
{
	const int LIMIT = 1024;  /* Upper limit for natural numbers */
	int sum = 0;             /* Variable to store the sum */
	int i;                   /* Loop variable */

	/* Iterate through numbers below LIMIT */
	for (i = 1; i < LIMIT; i++)
	{
		/* Check if the number is a multiple of 3 or 5 */
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;  /* Add to the sum if it's a multiple */
		}
	}

	/* Output the result */
	printf("The sum of all multiples of 3 or 5 below %d is: %d\n", LIMIT, sum);

	return (0);  /* Return SUCCESS */
}
