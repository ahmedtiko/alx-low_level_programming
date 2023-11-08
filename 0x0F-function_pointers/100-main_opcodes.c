#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}

	int num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		fprintf(stderr, "Error\n");
		exit(2);
	}

	unsigned char *main_opcodes = (unsigned char *)&main;

	if (num_bytes > strlen((const char *)main_opcodes))
	{
		fprintf(stderr, "Error\n");
		exit(3);
	}

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", main_opcodes[i]);
	
		if (i < num_bytes - 1)
		{
			printf(" ");
		}
	}

	printf("\n");

	return (0);
}
