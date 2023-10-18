#include "main.h"

/**
  * cap_string - The main  function
  *
  * @str: Function parameter of the string
  *
  * Return: Void.
  */

char *cap_string(char *)
{
	int i = 0;
	int capitalize = 1;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',' || str[i] == ';' || str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == '"' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}')
		{
			capitalize = 1;
		}
		else if (capitalize && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
			capitalize = 0;
		}

		i++;
	}

	return (str);
}
