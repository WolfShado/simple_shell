#include "shell.h"

/**
 * exit_shell - Function to exit the shell.
 * @status: Exit status.
 * Return: Void.
 */
void exit_shell(int status)
{
	exit(status);
}

/**
 * print_environment - Function of the current env var ptr.
 * @envp:  env var ptr.
 * Return: Void.
 */
void print_environment(char **envp)
{
int i = 0;
if (envp == NULL)
return;
while (envp[i] != NULL)
{
_puts(envp[i]);
_puts("\n");
i++;
}
}
