#include <stdlib.h>
#include <time.h>
#include <stdio.h>

	/**
	 * This is the preferred style for multi-line
	 * comments in C source code.
	 * 
	 * Description:  if else function to determine output number is positive or negative,
	 * return 0 (success)
	 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* if-else function */
	if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	else if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	else
	{
		printf("%d is negative\n", n);
	}
	return (0);
}
