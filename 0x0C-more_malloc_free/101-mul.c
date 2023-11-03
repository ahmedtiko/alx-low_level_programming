#include "main.h"
/**
 * is_positive_number - Check if a string is a positive number.
 * @str: The input string to check.
 *
 * Return: 1 if the string is a positive number, 0 otherwise.
 */
int is_positive_number(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * main - Multiplies two positive numbers.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 if successful, 98 in case of errors.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}
	if (!is_positive_number(argv[1]) || !is_positive_number(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}
	unsigned long long num1 = strtoull(argv[1], NULL, 10);
	unsigned long long num2 = strtoull(argv[2], NULL, 10);
	unsigned long long result = num1 * num2;

	if (result > 0)
	{
		unsigned long long div = 1;
		unsigned long long temp = result;
		while (temp > 9)
		{
			temp /= 10;
			div *= 10;
		}
		while (div >= 1)
		{
			_putchar((result / div) + '0');
			result = result % div;
			div = div / 10;
		}
	}
	else
	{
		_putchar('0');
	}
	_putchar('\n');
	return (0);
}
