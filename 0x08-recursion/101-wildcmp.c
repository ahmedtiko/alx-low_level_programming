#include "main.h"

/**
 * wildcmp_recursive - recursively compare two strings with wildcard
 * @s1: first string
 * @s2: second string with wildcards
 * @s1_index: current index in s1
 * @s2_index: current index in s2
 * @star_index: index of the last '*'
 * Return: true if strings can be considered identical, false otherwise
 */

bool wildcmp_recursive(char *s1, char *s2, int s1_index, int s2_index, int star_index)
{
	if (s1[s1_index] == '\0' && s2[s2_index] == '\0')
	{
		return (true);
	}
	else if (s2[s2_index] == '*')
	{
		star_index = s2_index;
		s2_index++;
	}

	if (s1[s1_index] != '\0' && (s2[s2_index] == '?' || s1[s1_index] == s2[s2_index]))
	{
		if (wildcmp_recursive(s1, s2, s1_index + 1, star_index, star_index))
		{
			return (true);
		}
	}

	return (false);
}

/**
 * wildcmp - compares two strings with wildcard support
 * @s1: first string
 * @s2: second string with wildcards
 * Return: 1 if strings can be considered identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	return (wildcmp_recursive(s1, s2, 0, 0, -1) ? 1 : 0);
}
