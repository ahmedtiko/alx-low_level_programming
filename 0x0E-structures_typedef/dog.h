#include <stdio.h>
#include <stdlib.h>
#ifndef DOG_H
#define DOG_H
/**
 * struct dog - Represents information about a dog.
 *
 * @name: Pointer to a character array for the dog's name.
 * @age: The age of the dog as a floating-point number.
 * @owner: Pointer to a character array for the owner's name.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
void free_dog(dog_t *d);
#endif
