#include "shell.h"

/**
 * interact - returns true if shell is in the interactive mode.
 * @info: struct address.
 *
 * Return: 1 if interactive mode, 0 otherwise.
 */
int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is delimeter.
 * @c: the char to check.
 * @delim: the delimeter string.
 * Return: 1 if true, 0 if false.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - check for alphabetic characters.
 *@c: The char to input.
 *Return: 1 if c is alphabetic, 0 otherwise.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to int.
 *@s:  string to be converted.
 *Return: 0 if no numbers detected, converted number otherwise.
 */

int _atoi(char *s)
{
	int index, sign = 1, flag = 0, output;
	unsigned int r = 0;

	for (index = 0;  s[index] != '\0' && flag != 2; index++)
	{
		if (s[index] == '-')
			sign *= -1;

		if (s[index] >= '0' && s[index] <= '9')
		{
			flag = 1;
			r *= 10;
			r += (s[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -r;
	else
		output = r;

	return (output);
}