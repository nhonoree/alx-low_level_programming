#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int digit;

	/* Skip non-numeric characters and handle signs */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			break;
		}
		i++;
	}

	/* Convert the string to an integer */
	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';

		/* Check for overflow before multiplying and adding */
		if (result > (INT_MAX - digit) / 10)
		{
			return (sign == 1 ? INT_MAX : INT_MIN);
		}

		result = result * 10 + digit;
		i++;
	}

	return (result * sign);
}
