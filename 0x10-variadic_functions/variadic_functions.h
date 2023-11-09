#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct print_function - Struct for mapping format specifiers to functions.
 * @specifier: The format specifier.
 * @printer: The corresponding printer function.
 */

typedef struct print_function
{
	char specifier;
	void (*printer)(va_list);
} print_function_t;
void print_char(va_list ap);
void print_int(va_list ap);
void print_float(va_list ap);
void print_string(va_list ap);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
