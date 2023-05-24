#include "shell.h"

/**
 * _puts -  str printer.
 * @str:  strg's ptr.
 * Return: void
 */
void _puts(char *str)
{
	if (str == NULL)
		return;

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
