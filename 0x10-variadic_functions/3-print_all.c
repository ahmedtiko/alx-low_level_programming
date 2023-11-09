#include "variadic_functions.h"

/**
 * print_char - Prints a char.
 * @ap: Argument list.
 */

void print_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * print_int - Prints an int.
 * @ap: Argument list.
 */

void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - Prints a float.
 * @ap: Argument list.
 */

void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - Prints a string.
 * @ap: Argument list.
 */

void print_string(va_list ap)
{
	char *str = va_arg(ap, char *);

	if (str == NULL)
	{
		printf("(nil)");
	}
	else
	{
		printf("%s", str);
	}
}

/**
 * print_all - Prints anything based on format.
 * @format: Format string.
 */

void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0, j = 0;
	char *separator = "";

	print_t print[] = {
		{'c', print_char}
		{'i', print_int}
		{'f', print_float}
		{'s', print_string}
		{0, NULL}
	};

	va_start(ap, format);

	while (format && format[i])
	{
		j = 0;

		while (print[j].specifier)
		{
			if (format[i] == print[j].specifier)
			{
				printf("%s", separator);
				print[j].printer(ap);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}
