#include "shell.h"

/**
 * execute - Cmd execution function.
 * @cmd: cmd's ptr
 * @argv: cmd's arg ptr.
 * @av: Program's arg ptr.
 * @envp: env var ptr.
 * Return: Int .
 */
int execute(char *cmd, char **argv, char **av, char **envp)
{
	pid_t pid;
	int status;
	char *full_path = path(cmd);
pid = fork();
if (pid == -1)
{
perror(av[0]);
free(full_path);
return (-1);
}
else if (pid == 0)
{
if (execve(full_path, argv, envp) == -1 && execve(cmd, argv, NULL) == -1)
{
perror(av[0]);
free(full_path);
exit(EXIT_FAILURE);
}
}
else
{
if (waitpid(pid, &status, 0) == -1)
{
perror(av[0]);
free(full_path);
return (-1);
}
}
free(full_path);
return (-1);
}
