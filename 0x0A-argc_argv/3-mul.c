#include "main.h"

/**
 * main - Entry point for the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 for success, 1 for error.
 */

int main(int argc, char *argv[])
{
	int n1, n2, r;
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);

	r = n1 * n2;

	printf("%d\n", r);

	return (0);
}
