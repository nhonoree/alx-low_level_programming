#include "main.h"
#include <stdlib.h>

/**
 * word_count - Counts the number of words in a string.
 * @str: The string to evaluate.
 *
 * Return: The number of words.
 */
int word_count(char *str)
{
	int i, count = 0, in_word = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of words, or NULL if it fails.
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, word_len, word_count(char *);
	int wc = word_count(str);

	if (wc == 0)
		return (NULL);

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, k = 0; i < wc; i++)
	{
		while (str[k] == ' ')
			k++;
		word_len = 0;
		while (str[k + word_len] && str[k + word_len] != ' ')
			word_len++;
		words[i] = malloc((word_len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}
		for (j = 0; j < word_len; j++)
			words[i][j] = str[k++];
		words[i][j] = '\0';
	}
	words[i] = NULL;

	return (words);
}
