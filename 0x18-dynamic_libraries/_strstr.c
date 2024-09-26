#include "main.h"

char *_strstr(char *haystack, char *needle)
{
    char *h, *n;

    while (*haystack)
    {
        h = haystack;
        n = needle;

        while (*h && *n && *h == *n)
        {
            h++;
            n++;
        }

        if (!*n)
            return haystack;
        haystack++;
    }

    return NULL;
}
