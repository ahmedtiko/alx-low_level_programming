#include "dog.h"

/**
 * init_dog - Initializes a struct dog with given values.
 * @d: Pointer to a struct dog to be initialized.
 * @name: Pointer to a character array containing the dog's name.
 * @age: The age of the dog as a floating-point number.
 * @owner: Pointer to a character array containing the owner's name.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d -> name = name;
		d -> age = age;
		d -> owner = owner;
	}
}
