#include "main.h"
#include <stddef.h>

char *_strpbrk(char *s, char *accept)
{
    while (*s)
    {
        char *a = accept;
        while (*a)
        {
            if (*s == *a)
                return (s);
            a++;
        }
        s++;
    }
    return NULL; // Return NULL if no match is found.
}
