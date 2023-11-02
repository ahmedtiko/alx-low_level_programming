#include "main.h"

/**
 * _calloc - Allocate memory for an array and initialize it to 0
 * @nmemb: Number of elements in the array
 * @size: Size of each element in bytes
 *
 * Return: Pointer to the allocated memory or NULL on failure
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;
	unsigned int t_size;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	t_size = nmemb * size;
	ptr = malloc(t_size);

	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < t_size; i++)
	{
		ptr[i] = 0;
	}

	return (ptr);
}
