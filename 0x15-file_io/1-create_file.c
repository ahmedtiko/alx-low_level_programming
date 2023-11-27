#include "main.h"

/**
 * create_file - Creates a file with specified permissions & writes text to it
 * @filename: The name of the file to create.
 * @text_content: A NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_d, write_s, i;

	if (filename == NULL)
	{
		return (0);
	}

	file_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file_d == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;

		write_s = write(file_d, text_content, i);
		if (write_s == -1)
		{
			close(file_d);
			return (-1);
		}
	}
	close(file_d);
	return (1);
}
