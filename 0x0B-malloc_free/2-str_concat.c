#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to the newly allocated string, or NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *concat;
	int l1, l2, i, j;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	for (l1 = 0; s1[l1]; l1++)
	{
	}
	for (l2 = 0; s2[l2]; l2++)
	{
	}

	concat = (char *)malloc(length1 + length2 + 1);

	if (concat == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < l1; i++)
	{
		concat[i] = s1[i];
	}
	for (j = 0; j < l2; j++)
	{
		concat[i + j] = s2[j];
	}

	concat[i + j] = '\0';

	return (concat);
}
