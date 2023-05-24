#include "shell.h"

/**
 * handle_ctrl - Ctrl-C signal function.
 * @signal: Signal nbr.
 * Return: Void
 */
void handle_ctrl(int signal)
{
	(void)signal;
	write(1, "\n$ ", 4);
}
