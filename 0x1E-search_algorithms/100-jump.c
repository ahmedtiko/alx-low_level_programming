#include "search_algos.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/**
 * jump_search - Searches for a value in a sorted array of integers using
 * the Jump search algorithm.
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value in array, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	int step, prev, i;

	step = sqrt(size);
	prev = 0;

	if (array == NULL)
		return (-1);

	printf("Value checked array[%d] = [%d]\n", prev, array[prev]);

	while (array[MIN(step, size) - 1] < value)
	{
		prev = step;
		step += sqrt(size);

		if (prev >= (int)size)
			return (-1);

		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
	}

	printf("Value found between indexes [%d] and [%d]\n", prev, prev + step);

	for (i = prev; i < min(step, size); i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
	}

	return (-1);
}
