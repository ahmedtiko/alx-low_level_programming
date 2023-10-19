#include "main.h"

/**
  *leet - main function
  *
  *@n: Function parameter
  *
  *Return: value of n
 */

char *leet(char *n) 
{
	char leetChars[] = "aAeEoOtTlL";
	char leetReplacements[] = "4433007711";
	int i, j;

	for (i = 0; n[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (n[i] == leetChars[j])
			{
				n[i] = leetReplacements[j];
			}
		}
	}

	return (n);
}
