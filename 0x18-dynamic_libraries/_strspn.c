#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    char *p;

    while (*s)
    {
        for (p = accept; *p != '\0'; p++)
        {
            if (*s == *p)
            break;
        }
        if (*p == '\0')
            break;
        count++;
        s++;
    }

    return count;
}
