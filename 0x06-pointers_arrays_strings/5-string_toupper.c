#include "main.h"

/**
 * string_toupper - main function
 *
 * @n: String input
 *
 * Return: dest
 */

char *string_toupper(char *n)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}

		i++;
	}

	return (str);
}
