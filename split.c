#include "shell.h"

/**
 * split - Spliter function from str to tokens.
 * @line: String's ptr.
 * Return: Tokens array.
 */
char **split(char *line)
{
	char *token;
	char **tokens = malloc(100 * sizeof(char *));
	int i = 0;
if (!tokens)
{
perror("Failed to allocate memory");
exit(EXIT_FAILURE);
}
token = strtok(line, " \t\n");
while (token != NULL && i < 99)
{
tokens[i] = token;
token = strtok(NULL, " \t\n");
i++;
}
tokens[i] = NULL;
return (tokens);
}
