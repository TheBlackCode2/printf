#include "main.h"

/**
 * put_char - prints the character c to
 *              the standard output (stdout)
 * @c: the input character
 * Return: 1 if success, otheriwse -1
*/
int put_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * puts - prints a string to the standard output
 * @s: the input string
 * Return: the number of characters printed
*/
int puts(const char *s)
{
	if (*s == '\0')
		return (0);
	put_char(*s);
	return (1 + puts(s + 1));
}
