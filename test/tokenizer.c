#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int index, x, y, z, n_words = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (index = 0; str[index] != '\0'; index++)
		if (!is_delim(str[index], d) && (is_delim(str[index + 1], d) || !str[index + 1]))
			n_words++;

	if (n_words == 0)
		return (NULL);
	p = malloc((1 + n_words) * sizeof(char *));
	if (!p)
		return (NULL);
	for (index = 0, x = 0; x < n_words; x++)
	{
		while (is_delim(str[index], d))
			index++;
		y = 0;
		while (!is_delim(str[index + y], d) && str[index + y])
			y++;
		p[x] = malloc((y + 1) * sizeof(char));
		if (!p[x])
		{
			for (y = 0; y < x; y++)
				free(p[y]);
			free(p);
			return (NULL);
		}
		for (z = 0; z < y; z++)
			p[x][z] = str[index++];
		p[x][z] = 0;
	}
	p[x] = NULL;
	return (p);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int index, x, y, z, n_words = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (index = 0; str[index] != '\0'; index++)
		if ((str[index] != d && str[index + 1] == d) ||
		    (str[index] != d && !str[index + 1]) || str[index + 1] == d)
			n_words++;
	if (n_words == 0)
		return (NULL);
	p = malloc((1 + n_words) * sizeof(char *));
	if (!p)
		return (NULL);
	for (index = 0, x = 0; x < numwords; x++)
	{
		while (str[index] == d && str[index] != d)
			index++;
		y = 0;
		while (str[index + y] != d && str[index + y] && str[index + y] != d)
			y++;
		p[x] = malloc((y + 1) * sizeof(char));
		if (!s[x])
		{
			for (y = 0; y < x; y++)
				free(p[y]);
			free(p);
			return (NULL);
		}
		for (z = 0; z < y; z++)
			p[x][z] = str[index++];
		p[x][z] = 0;
	}
	p[x] = NULL;
	return (p);
}
