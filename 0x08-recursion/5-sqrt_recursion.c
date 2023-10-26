#include "main.h"

/**
 * sqrt_recursive - helper function for calculating the square root recursively
 * @n: the number to find the square root of
 * @guess: current guess for the square root
 * Return: the natural square root or -1 if not found
 */

int sqrt_recursive(int n, int guess)
{
	if ((guess * guess) == n)
	{
		return (guess);
	}
	else if ((guess * guess) > n)
	{
		return (-1);
	}

	return (sqrt_recursive(n, guess + 1));
}

/**
 * _sqrt_recursion - calculates the natural square root of a number
 * @n: the number to find the square root of
 * Return: the natural square root or -1 if not found
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (sqrt_recursive(n, 0));
}
