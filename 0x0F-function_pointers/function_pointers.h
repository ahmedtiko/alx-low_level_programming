#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

int _putchar(char);
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));
#endif
