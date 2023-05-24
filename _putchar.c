#include "shell.h"
#include <unistd.h>
/**
 * _putchar - writes the char c to stdout.
 * @c:  char to print.
 * Return: On success, the nbr of char written is returned.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
