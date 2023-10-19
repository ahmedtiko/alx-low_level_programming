#include "main.h"

/**
  * cap_string - The main  function
  *
  * @str: Function parameter of the string
  *
  * Return: Void.
  */

char *cap_string(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',' || str[i] == ';' || str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == '"' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}')
			{
				str[i] = str[i] - 32;
			}
		}

		i++;
	}

	return (str);
}
