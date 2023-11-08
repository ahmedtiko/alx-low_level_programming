#include "function_pointers.h"

/**
 * array_iterator - Iterates over an array and applies a fn to each element
 * @array: Pointer to an integer array.
 * @size: The size of the array.
 * @action: A pointer to the function to be applied to each element.
 *
 * Return: Nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || size == 0 || action == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
