#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */

char *_strcat(char *dest, char *src)
{
	int length;
	int i;

	length = 0;

	while (dest[length] != '\0')
	{
		length++;
	}

	i = 0;

	while (src[i] != '\0')
	{
		dest[length] = src[i];
		length++;
		i++;
	}

	dest[length] = '\0';

	return (dest);
}
