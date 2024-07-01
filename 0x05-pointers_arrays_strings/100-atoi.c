#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    // Skip leading whitespace
    while (s[i] == ' ')
        i++;

    // Check sign
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    // Convert digits to integer
    while (s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';

        // Check for overflow before updating result
        if (sign == 1 && (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)))
        {
            return INT_MAX; // Return maximum possible value
        }
        else if (sign == -1 && (result > -(INT_MIN / 10) || (result == -(INT_MIN / 10) && digit > -(INT_MIN % 10))))
        {
            return INT_MIN; // Return minimum possible value
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}
