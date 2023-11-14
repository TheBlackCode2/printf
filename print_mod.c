#include "main.h"

/**
 * print_ft - prints a range of char address
 * @start: start address
 * @end: stop address
 * @e: except address
 * Return: the number of printed characters
*/
int print_ft(char *start, char *end, char *e)
{
	int i = 0;

	while (start <= end)
	{
		if (start != e)
			i += _putchar_(*start);
		start++;
	}
	return (i);
}

/**
 * print_rev_str - prints input string in reverse
 * @args: the input arguments
 * Return: the number of printed characters
*/
int print_rev_str(va_list args, params *p)
{
	int i, j = 0;
	char *s = va_arg(args, char *);
	(void)p;

	if (s)
	{
		for (i = 0; *s; s++)
			i++;
		s--;
		for (; i > 0; i--, s--)
			j += _putchar_(*s);
	}
	return (j);

}

/**
 * print_rot13_str - prints the input
 *                string in rot13
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of printed characters
*/
int print_rot13_str(va_list args, params *p)
{
	int i = 0, j = 0;
	int count = 0;
	char a[] = "NOPQRSTUVWXYZABCDEFGHIJKLM  nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(args, char *);
	(void)p;

	while (s[i])
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			j = s[i] - 65;
			count += _putchar_(a[j]);
		}
		else
			count += _putchar_(s[i]);
		i++;
	}
	return (count);
}
