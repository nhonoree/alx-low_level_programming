#include "main.h"
#include <stddef.h>

char *_strchr(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    return NULL; // Ensure you return NULL if the character isn't found.
}
