#include "main.h"

int main(int argc, char *argc[])
{
	int n1, n2, r;
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);
	r = n1 * n2;
	printf("%d\n", r);

	return (0);
}
