#include "main.h"

/**
  *leet - main function
  *
  * @n: Function parameter
  *
  *Return: value of n
 */

char *leet(char *str) 
{
	char *leetChars = "aAeEoOtTlL";
	char *leetReplacements = "4433007711";
	int i, j;

	for (i = 0; str[i] != '\0'; i++) 
	{
		for (j = 0; leetChars[j] < 10; j++)
		{
			if (str[i] == leetChars[j])
			{
				str[i] = leetReplacements[j];
			}
		}
	}

	return (str);
}
