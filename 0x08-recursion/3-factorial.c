#include "main.h"

/**
 * factorial - return factorial of a given number
 *
 * @n: parameter input
 *
 * Retrun: -1 if input less than 0
 * Return: 1 if input is 0
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}
