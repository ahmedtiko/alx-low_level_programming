#ifndef _SIMPLE_H_
#define _SIMPLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* RD/WR buffers */
#define RD_BUFF_SIZE 1024
#define WR_BUFF_SIZE 1024
#define BUFF_FLUSH -1

/* command chain */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* convert_number() */
#define CONVERT_LC	1
#define CONVERT_UNSIGN	2

#define HIST_FILE	".SimpleShell_Hist"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Structure to hold information for the shell program.
 * @arg: Current command line argument.
 * @argv: Array of command line arguments.
 * @path: Path associated with the command.
 * @argc: Number of command line arguments.
 * @line_count: Count of lines processed.
 * @err_num: Error number if an error occurs.
 * @linecount_flag: Flag to indicate if line count needs to be incremented.
 * @fname: File name associated with the command.
 * @env: Linked list for environment variables.
 * @history: Linked list to store command history.
 * @alias: Linked list to store command aliases.
 * @environ: Array of environment variables.
 * @env_changed: Flag to indicate if the environment has been modified.
 * @status: Exit status of the last executed command.
 * @cmd_buff: Pointer to command buffer; chain buffer for memory management.
 * @cmd_buf_type: Type of command buffer (CMD_type ||, &&, ;).
 * @readfd: File descriptor for reading input.
 * @histcount: History count.
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buff;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - Structure to define built-in commands
 *		and their associated functions.
 * @type: String representing the built-in command.
 * @func: Pointer to the function implementing the built-in command.
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* fn_shell_loop.c */
int hash(info_t *, char **);
int find_built_in(info_t *);
void find_command(info_t *);
void fork_command(info_t *);

/* fn_parser.c */
int _iscmd(info_t *, char *);
char *dup_char(char *, int, int);
char *find_path(info_t *, char *, char *);

/* fn_errors.c */
void _eputs(char *);
int _eputch(char);
int _putfds(char c, int fd);
int _putsfds(char *str, int fd);

/* fn_string.c */
int str_len(char *);
int str_cmp(char *, char *);
char *starts_with(const char *, const char *);
char *str_cat(char *, char *);

/* fn_string1.c */
char *str_copy(char *, char *);
char *str_dupp(const char *);
void _puts(char *);
int _putchar(char);

/* fn_exits.c */
char *strn_copy(char *, char *, int);
char *strn_cat(char *, char *, int);
char *strn_char(char *, char);

/* fn_tokenizer.c */
char **str_tow(char *, char *);

/* fn_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* fn_memory.c */
int be_free(void **);

/* fn_atoi.c */
int is_interactive(info_t *);
int is_delimeter(char, char *);
int is_alpha(int);
int _atoi(char *);

/* fn_errors1.c */
int error_atoi(char *);
void error_print(info_t *, char *);
int decimal_print(int, int);
char *cnv_n(long int, int, int);
void rm_comm(char *);

/* fn_builtin.c */
int is_exit(info_t *);
int _command(info_t *);
int _help(info_t *);

/* fn_builtin1.c */
int z_history(info_t *);
int z_alias(info_t *);

/*fn_getline.c */
ssize_t gett_input(info_t *);
int gett_line(info_t *, char **, size_t *);
void signin_Handler(int);

/* fn_getinfo.c */
void clear_inf(info_t *);
void set_inf(info_t *, char **);
void free_inf(info_t *, int);

/* fn_environ.c */
char *get_env(info_t *, const char *);
int z_env(info_t *);
int set_env(info_t *);
int unset_env(info_t *);
int inhabit_env_list(info_t *);

/* fn_getenv.c */
char **gett_environ(info_t *);
int un_setenv(info_t *, char *);
int sett_env(info_t *, char *, char *);

/* fn_history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* fn_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* fn_lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* fn_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
