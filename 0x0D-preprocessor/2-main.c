#include <stdio.h>
/**
 * main - Entry point of the program
 *
 * Description: This function prints the name of the file it was compiled from.
 *
 *Return: 0 on success
 */
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
