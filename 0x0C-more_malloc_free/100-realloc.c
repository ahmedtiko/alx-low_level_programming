#include "main.h"

/**
 * _realloc - Reallocate a memory block using malloc and free
 * @ptr: A pointer to the memory previously allocated with malloc
 * @old_size: The size, in bytes, of the allocated space for ptr
 * @new_size: The new size, in bytes, of the new memory block
 *
 * Return: Pointer to the newly reallocated memory block or NULL on failure
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i, min_size;

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);

		if (new_ptr == NULL)
		{
			return (NULL);
		}
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
	{
		return (NULL);
	}
	min_size = (old_size < new_size) ? old_size : new_size;

	for (i = 0; i < min_size; i++)
	{
		new_ptr[i] = ((char *)ptr)[i];
	}
	free(ptr);
	return (new_ptr);
}
