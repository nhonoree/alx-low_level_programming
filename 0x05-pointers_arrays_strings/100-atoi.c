#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the string.
 */
int _atoi(char *s)
{
    int result = 0;
    int sign = 1;
    int started = 0;
    int digit;

    while (*s)
    {
        if (*s == '-' || *s == '+')
        {
            if (started)
                break;
            if (*s == '-')
                sign *= -1;
        }
        else if (*s >= '0' && *s <= '9')
        {
            started = 1;
            digit = *s - '0';

            if (sign == 1)
            {
                if (result > (INT_MAX - digit) / 10)
                    return (INT_MAX);
            }
            else
            {
                if (result > (INT_MAX - digit + 1) / 10)
                    return (INT_MIN);
            }

            result = result * 10 + digit;
        }
        else if (started)
        {
            break;
        }
        s++;
    }

    return (sign * result);
}
