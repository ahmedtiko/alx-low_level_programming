#include <stdio.h>

/**
 * main funtion prints single digit numbers
 *
 * return alwaus 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d", i);
	}

	putchar('\n');
	return (0);
}
