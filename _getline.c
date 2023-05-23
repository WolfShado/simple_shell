#include "shell.h"

/**
* _getline - one line from the prompt Reader.
* @data: Program's data struct.
*
* Return: reading counting bytes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

/* checker of  existance for  more commands in the array */
/*  logical operators checker*/
if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
(array_operators[0] == '|' && errno == 0))
	{
/*if exists free the malloc in the array */
for (i = 0; array_commands[i]; i++)
{
free(array_commands[i]);
array_commands[i] = NULL;
}
/*  the file descriptor reader int to buff */
bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
if (bytes_read == 0)
return (-1);
/* lines spliter 4 \n or ; */
i = 0;
do {
array_commands[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));
/*checker and spliter of && and || */
i = check_logic_ops(array_commands, i, array_operators);
} while (array_commands[i++]);
}
/* next cmd obtained (command 0) and remove it for the array*/
data->input_line = array_commands[0];
for (i = 0; array_commands[i]; i++)
{
array_commands[i] = array_commands[i + 1];
array_operators[i] = array_operators[i + 1];
}
return (str_length(data->input_line));
}


/**
* check_logic_ops - checker and spliter for && and || ops
* @array_commands: array of the cmd.
* @i:  array_commands's index to be verified.
* @array_operators:  log ops array Foreach prv cmd
*
* Return: Last cmd's index in the array_commands.
*/
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
char *temp = NULL;
int j;
/* Look for & char in the cmd*/
for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
{
if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
{
/* Line spliter if chars && was found */
temp = array_commands[i];
array_commands[i][j] = '\0';
array_commands[i] = str_duplicate(array_commands[i]);
array_commands[i + 1] = str_duplicate(temp + j + 2);
i++;
array_operators[i] = '&';
free(temp);
j = 0;
}
if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
{
/* Line spliter if chars || was found */
temp = array_commands[i];
array_commands[i][j] = '\0';
array_commands[i] = str_duplicate(array_commands[i]);
array_commands[i + 1] = str_duplicate(temp + j + 2);
i++;
array_operators[i] = '|';
free(temp);
j = 0;
}
}
return (i);
}
