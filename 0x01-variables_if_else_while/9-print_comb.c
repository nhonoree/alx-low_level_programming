#include <stdio.h>

/**
	* main - Entry point
	*
	* Return: Always 0 (Success)
	*/
int main(void)
{
	int digit;

	for (digit = 0; digit <= 9; digit++)
	{
	putchar(digit + '0');  /* Print the digit character */

	if (digit < 9)
	{
	putchar(',');      /* Print the comma */
	putchar(' ');      /* Print the space */
	}
	}
	putchar('\n');             /* Print the newline */

	return (0);
}
