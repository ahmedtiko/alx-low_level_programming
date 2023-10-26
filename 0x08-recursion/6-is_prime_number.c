#include "main.h"

/**
 * is_divisible - checks if a number is divisible by another number
 * @n: the number to be checked
 * @div: the number to divide by
 * Return: 1 if divisible, 0 if not
 */

int is_divisible(int n, int div)
{
	if (div <= 1)
	{
		return (0);
	}
	else if (div == 2)
	{
		return ((n % div == 0) ? 1 : 0);
	}
	else if (n % div == 0)
	{
		return (1);
	}

	return (is_divisible(n, div - 1));
}

/**
 * is_prime_number - checks if a number is a prime number
 * @n: the number to be checked
 * Return: 1 if prime, 0 if not
 */

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	else if (n <= 3)
	{
		return (1);
	}
	else if (is_divisible(n, n - 1))
	{
		return (0);
	}

	return (1);
}
