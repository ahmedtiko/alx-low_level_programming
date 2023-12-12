#include "simple.h"

/**
 * input_buf - buffer chained commands.
 * @info: parameter struct.
 * @buf: address of buffer.
 * @len: address of len var.
 *
 * Return: bytes read.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* remove newlines */
				r--;
			}
			info->linecount_flag = 1;
			rm_comm(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = r;
				info->cmd_buff = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - get a line minus the new line.
 * @info: parameter struct.
 *
 * Return: bytes read.
 */
ssize_t get_input(info_t *info)
{
	static char *buff;
	static size_t index, x, l;
	ssize_t r = 0;
	char **buff_p = &(info->arg), *ptr;

	_putchar(BUFF_FLUSH);
	r = input_buf(info, &buff, &l);
	if (r == -1)
		return (-1);
	if (l)
	{
		x = index;
		ptr = buff + index;

		check_chain(info, buff, &x, index, l);
		while (x < l)
		{
			if (is_chain(info, buff, &x))
				break;
			x++;
		}

		index = x + 1;
		if (index >= l)
		{
			index = l = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buff_p = ptr;
		return (str_len(ptr));
	}

	*buff_p = buff;
	return (r);
}

/**
 * read_buf - reads buffer.
 * @info: parameter struct.
 * @buf: buffer.
 * @i: size.
 *
 * Return: r.
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, RD_BUFF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - Get the next line of input from STDIN.
 * @info: Parameter struct.
 * @ptr: Address of a pointer to buffer, preallocated or NULL.
 * @length: Size of preallocated ptr buffer if not NULL.
 *
 * Return: s.
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buff[RD_BUFF_SIZE];
	static size_t index, l;
	size_t y;
	ssize_t r = 0, s = 0;
	char *ptrx = NULL, *new_ptr = NULL, *pc;

	ptrx = *ptr;
	if (ptrx && length)
		s = *length;
	if (index == l)
		index = l = 0;

	r = read_buf(info, buff, &l);
	if (r == -1 || (r == 0 && l == 0))
		return (-1);

	pc = strn_char(buff + index, '\n');
	y = pc ? 1 + (unsigned int)(pc - buff) : l;
	new_ptr = _realloc(ptrx, s, s ? s + y : y + 1);
	if (!new_ptr)
		return (ptrx ? free(ptrx), -1 : -1);

	if (s)
		strn_cat(new_ptr, buff + index, y - index);
	else
		strn_copy(new_ptr, buff + index, y - index + 1);

	s += y - index;
	index = y;
	ptrx = new_ptr;

	if (length)
		*length = s;
	*ptr = ptrx;
	return (s);
}

/**
 * sigintHandler - blocks the ctrl-C(COPY).
 * @sig_num: the signal number.
 *
 * Return: void.
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFF_FLUSH);
}
