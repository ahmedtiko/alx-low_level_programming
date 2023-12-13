#include "simple.h"

/**
 * be_free - free the pointer and NULLS the addresses.
 * @ptr: address of the pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
 */
int be_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
