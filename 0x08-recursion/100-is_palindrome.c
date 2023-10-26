#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: input string
 * Return: length of the string
 */

int _strlen(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	return (1 + _strlen(s + 1));
}

/**
 * is_palindrome_recursive - checks if a string is a palindrome recursively
 * @s: input string
 * @start: start index
 * @end: end index
 * Return: true if palindrome, false otherwise
 */

bool is_palindrome_recursive(char *s, int start, int end)
{
	if (start >= end)
	{
		return (true);
	}
	else if (s[start] != s[end])
	{
		return (false);
	}

	return (is_palindrome_recursive(s, start + 1, end - 1));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: input string
 * Return: 1 if palindrome, 0 if not
 */

int is_palindrome(char *s)
{
	int length;

	length = _strlen(s);

	if (length <= 1)
	{
		return (1);
	}

	return (is_palindrome_recursive(s, 0, length - 1));
}
