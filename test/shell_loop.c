#include "simple.h"

/**
 * hash - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hash(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_inf(info);
		if (is_interactive(info))
			_puts("$ ");
		_eputch(BUFF_FLUSH);
		r = gett_input(info);
		if (r != -1)
		{
			set_inf(info, av);
			builtin_ret = find_built_in(info);
			if (builtin_ret == -1)
				find_command(info);
		}
		else if (is_interactive(info))
			_putchar('\n');
		free_inf(info, 0);
	}
	write_history(info);
	free_inf(info, 1);
	if (!is_interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_built_in - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if built_in not found,
 *	0 successfull,
 *	1 if not successful,
 *	-2 if signals exit()
 */
int find_built_in(info_t *info)
{
	int index, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", is_exit},
		{"env", z_env},
		{"help", _help},
		{"history", z_history},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", _command},
		{"alias", z_alias},
		{NULL, NULL}
	};

	for (index = 0; builtintbl[index].type; index++)
		if (str_cmp(info->argv[0], builtintbl[index].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[index].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_command - finds a command in PATH
 * @info: the parameter & return info struct
 * Return: void
 */
void find_command(info_t *info)
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
		if (!is_delimeter(info->arg[index], " \t\n"))
			y++;
	if (!y)
		return;

	path = find_path(info, get_env(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_command(info);
	}
	else
	{
		if ((is_interactive(info) || get_env(info, "PATH=")
			|| info->argv[0][0] == '/') && _iscmd(info, info->argv[0]))
			fork_command(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			error_print(info, "not found\n");
		}
	}
}

/**
 * fork_command - forks an exec() thread to run command
 * @info: param. & return info struct
 * Return: void
 */
void fork_command(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, gett_environ(info)) == -1)
		{
			free_inf(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				error_print(info, "Permission denied\n");
		}
	}
}
