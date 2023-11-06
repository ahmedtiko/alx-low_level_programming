#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
 * print_dog - Prints information about a dog
 * @d: A pointer to the dog struct
 *
 * Description: This function prints details about a dog, including its name,
 * age, and owner. If any of these fields is NULL, it prints "(nil)" in place
 * of the missing value.
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		if (d->name != NULL)
		{
			printf("Name: %s\n", d->name);
		}
		else
		{
			printf("Name: (nil)\n");
		}

		printf("Age: %f\n", d->age);

		if (d->owner != NULL)
		{
			printf("Owner: %s\n", d->owner);
		}
		else
		{
			printf("Owner: (nil)\n");
		}
	}
}
