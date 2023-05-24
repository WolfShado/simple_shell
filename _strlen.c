#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: string's ptr.
 * Return :string's lenght.
 */
int _strlen(char *s)
{
int len = 0;
if (s == NULL)
return (0);
while (s[len] != '\0')
len++;
return (len);
}
