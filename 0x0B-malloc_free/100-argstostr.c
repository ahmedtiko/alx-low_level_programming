#include "main.h"

/**
 * argstostr - Concatenate all arguments of the program
 * @ac: The number of arguments
 * @av: An array of argument strings
 *
 * Return: A pointer to a new string, or NULL if it fails
 */

char *argstostr(int ac, char **av)
{
	int t_length = 0;
	char *result;
	int i, j, k;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			t_length++;
		}
		t_length++;
	}
	t_length++;

	result = malloc(t_length * sizeof(char));

	if (result == NULL)
	{
		return (NULL);
	}

	k = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			result[k] = av[i][j];
			k++;
		}
		result[k] = '\n';
		k++;
	}
	result[k] = '\0';

	return (result);
}
