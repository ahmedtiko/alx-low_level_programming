#include "main.h"

/**
 * wc_r - recursively compare two strings with wildcard
 * @s1: first string
 * @s2: second string with wildcards
 * @s1_i: current index in s1
 * @s2_i: current index in s2
 * @star_i: index of the last '*'
 * Return: true if strings can be considered identical, false otherwise
 */

bool wc_r(char *s1, char *s2, int s1_i, int s2_i, int star_i)
{
	if (s1[s1_i] == '\0' && s2[s2_i] == '\0')
	{
		return (true);
	}
	else if (s2[s2_i] == '*')
	{
		star_i = s2_i;
		s2_i++;
	}

	if (s1[s1_i] != '\0' && (s2[s2_i] == '?' || s1[s1_i] == s2[s2_i]))
	{
		if (wc_r(s1, s2, s1_i + 1, star_i, star_i))
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
	return (wc_r(s1, s2, 0, 0, -1) ? 1 : 0);
}
