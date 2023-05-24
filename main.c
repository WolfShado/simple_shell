#include "shell.h"

/**
 * main - Main function of the program.
 * @argc: cmd-line arg nbr.
 * @argv: cmd-line arg array.
 * @envp: Env var array.
 * Return: Int.
 */
int main(int argc, char **argv, char **envp)
{
(void)argc;
signal(SIGINT, handle_ctrl);
prompt(argv, envp);
return (0);
}
