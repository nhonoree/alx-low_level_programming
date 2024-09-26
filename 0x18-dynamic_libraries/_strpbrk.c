#include "main.h"

char *_strpbrk(char *s, char *accept)
{
    char *p;

    while (*s)
    {
        for (p = accept; *p != '\0'; p++)
        {
            if (*s == *p)
                return s;
        }
        s++;
    }

    return NULL;
}
