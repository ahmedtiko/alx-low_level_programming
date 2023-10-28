#include "main.h"

/**
 * is_positive_number - Check if a string is a positive number.
 * @str: The string to check.
 *
 * Return: 1 if str is a positive number, 0 otherwise.
 */

int is_positive_number(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}

		i++;
	}

	return (1);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * Return: 0 if successful, 1 if there was an error
 */

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}

	int sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (!is_positive_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
