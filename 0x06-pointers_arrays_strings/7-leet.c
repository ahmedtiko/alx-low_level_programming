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
	char *leetReplacements = "4337011";
	int i, j;

	for (i = 0; str[i] != '\0'; i++) 
	{
		for (j = 0; leetChars[j] != '\0'; j++)
		{
			if (str[i] == leetChars[j])
			{
				str[i] = leetReplacements[j];
				break;
			}
		}
	}

	return (str);
}
