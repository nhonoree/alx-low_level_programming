#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *s)
{
	int i = 0;

	if (s[i] >= 'a' && s[i] <= 'z')
	{
		s[i] = s[i] - 32;
	}
	i++;
	while (s[i] != '\0')
	{
		if ((s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n' ||
		     s[i - 1] == ',' || s[i - 1] == ';' || s[i - 1] == '.' ||
		     s[i - 1] == '!' || s[i - 1] == '?' || s[i - 1] == '"' ||
		     s[i - 1] == '(' || s[i - 1] == ')' || s[i - 1] == '{' ||
		     s[i - 1] == '}') && (s[i] >= 'a' && s[i] <= 'z'))
		{
			s[i] = s[i] - 32;
		}
		i++;
	}
	return (s);
}
