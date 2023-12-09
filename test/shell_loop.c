#include "shell.h"

/**
 * hsh - Main shell loop.
 * @info: The parameter & return info structure.
 * @av: The args vector from main().
 *
 * Return: 0 on success, 1 on error, or error code.
 */
int hsh(info_t *info, char **av)
{
	ssize_t read_result = 0;
	int builtin_return = 0;

	while (read_result != -1 && builtin_return != -2)
	{
		clear_info(info);

		if (interactive(info))
			_puts("$ ");

		_eputch(BUF_FLUSH);

		read_result = get_input(info);
		if (read_result != -1)
		{
			set_info(info, av);
			builtin_return = find_builtin(info);
			if (builtin_return == -1)
				find_cmd(info);
		}
		else if (interactive(info))
		{
			_putchar('\n');
		}

		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);

	if (!interactive(info) && info->status)
		exit(info->status);

	if (builtin_return == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_return);
}

/**
 * find_builtin - Finds a builtin command.
 * @info: The parameter & return info structure.
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit().
 */
int find_builtin(info_t *info)
{
	int index, built_in_return = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (index = 0; builtintbl[index].type; index++)
		if (_strcmp(info->argv[0], builtintbl[index].type) == 0)
		{
			info->line_count++;
			built_in_return = builtintbl[index].func(info);
			break;
		}
	return (built_in_return);
}

/**
 * find_cmd - Finds a command in the path.
 * @info: the parameter & return info structure.
 *
 * Return: void.
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int index, y;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (index = 0, y = 0; info->arg[index]; index++)
		if (!is_delim(info->arg[index], " \t\n"))
			y++;
	if (!y)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - Forks a, an executed thread to run cmd.
 * @info: the parameter & return info struct.
 *
 * Return: void.
 */
void fork_cmd(info_t *info)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	/* child */
	if (pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	/* parent */
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
