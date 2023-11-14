#include "main.h"

/**
 * _puts_ - prints an input string
 *        followed bt new line
 * @s: the input string
 * Return: the number of printed characters
*/
int _puts_(char *s)
{
	char *i = s;

	while (*s != '\0')
		_putchar_(*s++);
	return ((int)(s - i));
}

/**
 * _putchar_ - writes the input character to
 *           the standard output (strout)
 * @c: the input character
 * Return: 1 id success, otherwise -1
*/
int _putchar_(int c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c == -1 || i >= BUFFER_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;
	return (1);
}
