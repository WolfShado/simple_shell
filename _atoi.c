#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode.
 * @info: adress of struct.
 *
 * Return: 1 if interactive mode, else 0 .
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - character, delimeter checker.
 * @c: char to check.
 * @delim: str's delimeter.
 * Return: 1  T, 0 F.
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}
/**
 *_isalpha - alphabetic char checker.
 *@c:  char to input.
 *Return: 1 if c is letter, else 0.
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
/**
 *_atoi - from  str to  int.
 *@s: str to be converted.
 *Return: 0 if str num is null,else converted num.
 */
int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;
for (i = 0;  s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}
