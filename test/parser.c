#include "simple.h"

/**
 * is_cmd - Determine if the file is an executable command.
 * @info: The info struct.
 * @path: Path to the file.
 *
 * Return: 1 if true, 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat file_stat;

	(void)info;
	if (!path || stat(path, &file_stat))
	{
		return (0);
	}
	if (file_stat.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Duplicate chars.
 * @pathstr: The Path string.
 * @start: starting index.
 * @stop: stopping index.
 *
 * Return: pointer to the new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buff[1024];
	int index = 0, y = 0;

	for (y = 0, index = start; index < stop; index++)
		if (pathstr[index] != ':')
			buff[y++] = pathstr[index];
	buff[y] = 0;
	return (buff);
}

/**
 * find_path - finds this cmd in the Path string.
 * @info: the info struct.
 * @pathstr: the PATH string.
 * @cmd: the cmd to find.
 *
 * Return: full path of cmd if found or NULL.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int index = 0, curr_position = 0;
	char *p;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[index] || pathstr[index] == ':')
		{
			p = dup_chars(pathstr, curr_position, index);
			if (!*p)
				_strcat(p, cmd);
			else
			{
				_strcat(p, "/");
				_strcat(p, cmd);
			}
			if (is_cmd(info, p))
				return (p);
			if (!pathstr[index])
				break;
			curr_position = index;
		}
		index++;
	}
	return (NULL);
}
