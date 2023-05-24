#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @s1: 1st str.
 * @s2: 2nd str.
 * Return: Negative value if s1 is less than s2,
 *	0 if s1 is equal to s2,
 *	Positive value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
