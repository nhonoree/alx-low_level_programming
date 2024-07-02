#include "main.h"

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
            result = result * 10 + (*s - '0');
        }
        else if (started)
        {
            break;
        }
        s++;
    }

    return (sign * result);
}

