#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int index = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int l = 0;
	char *r;

	if (str == NULL)
		return (NULL);
	while (*str++)
		l++;
	r = malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	for (l++; l--;)
		ret[l] = *--str;
	return (r);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int index = 0;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int index;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || index >= WRITE_BUF_SIZE)
	{
		write(1, buff, index);
		index = 0;
	}
	if (c != BUF_FLUSH)
		buff[index++] = c;
	return (1);
}