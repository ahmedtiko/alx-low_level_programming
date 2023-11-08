#include "function_pointers.h"
#include <stddef.h>
#include <stdio.h>
/**
 * array_iterator - Iterates over an array and applies a function to each element.
 * @array: Pointer to an integer array.
 * @size: The size of the array.
 * @action: A pointer to the function to be applied to each element.
 *
 * Desc: This fn iterates over the elements of the integer array &
 * applies the provided function 'action' to each element.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || size == NULL || action == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
