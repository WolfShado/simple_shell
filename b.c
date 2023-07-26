#include "shell.h"

/**
 * builtin_exit - exits the shell
 *
 * @status: exit status
 * @av: array of cmd line args
 * @sh: program name
 */
void builtin_exit(char *status, char **av, char *sh)
{
int exit_code;
if (status)
{
exit_code = _atoi(status);
if (exit_code < 0 || !is_number(status))
{
_putserr(sh);
_putserr(": 1: exit: Illegal number: ");
_putserr(status);
_puterr('\n');
exit_code = 2;
}
}
else
exit_code = 2;
free_grid(av);
exit(exit_code);
}
/**
 * builtin_env -Use the glob var env to  prints the env
 * Return: 0.
 */
int builtin_env(void)
{
int i = 0;
while (environ[i] != NULL)
{
_puts(environ[i]);
_putc('\n');
i++;
}
return (0);
}
