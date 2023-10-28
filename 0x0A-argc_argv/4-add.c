#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * Return: 0 if successful, 1 if there was an error
 */

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	int sum, i, num, j;

	sum = 0;

	for (i = 1; i < argc; i++)
	{
		num = 0;
		j = 0;

		while (argv[i][j] != '\0')
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}

			num = num * 10 + (argv[i][j] - '0');
			j++;
		}

		sum += num;
	}

	printf("%d\n", num);
	return (0);
}
