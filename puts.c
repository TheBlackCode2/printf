#include "main.h"

/**
 * puts - prints an input string
 *        followed bt new line
 * @s: the input string
 * Return: the number of printed characters
*/
int puts(char *s)
{
	char *i = s;

	while (*s != '\0')
		putchar(*s++);
	return (s - a);
}

/**
 * putchar - writes the input character to
 *           the standard output (strout)
 * @c: the input character
 * Return: 1 id success, otherwise -1
*/
int putchar(int c)
{
	static int i;
	static buffer[BUFFER_SIZE];

	if (c == -1 || i >= BUFFER_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;
	return (1);
}
