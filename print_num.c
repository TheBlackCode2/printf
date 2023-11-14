#include "main.h"

/**
 * isdigit - checks if character is digit
 * @c: the input character
 * Return: 1 if digit, otherwise 0[[I
*/
int isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/** 
 * getlen - gets length of an input string
 * @s: the input string
 * Return: string length
*/
int getlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + getlen(s + 1));
}

/**
 * print_num - prints an input number
 * @s: the input number as string
 * @p: the input struct info
*/
int print_num(char *s, params *p)
{
	unsigned int i = getlen(s);
	int n = (!p->unsign && *s == '-');

	if (!p->precision && *s == '0' && !s[1])
		s = "";
	if (n)
	{
		s++;
		i--;
	}
	if(p->precision != UINT_MAX)
		while (i++ < p->precision)
			*--s = '0';
	if (n)
		*--s = '-';

	if (!p->minus)
		return (print_num_rs(s, p));
	else
		return (print_num_ls(s, p));
}

/**
 * print_num_rs - prints an input number
 *             with right shift
 * @s: the input number as string
 * @p: the input struct info
*/
int print_num_rs(char *s, params *p)
{
	unsigned int n = 0;
	unsigned int neg1, neg2;
	unsigned int i = getlen(s);
	char pad = ' ';

	if (p->zero && !p->minus)
		pad = '0';
	neg1 = neg2 = (!p->unsign && *s == '-');
	if (neg1 && i < p->width && pad == '0' && !p->minus)
		s++;
	else
		neg1 = 0;
	if ((p->plus && !neg2) || (!p->plus && p->space && !neg2))
		i++;
	if (neg1 && pad == '0')
		n += _putchar_('-');
	if (p->plus && !neg2 && pad == '0' && !p->unsign)
		n += _putchar_('+');
	else if (!p->plus && p->space && !neg2 && !p->unsign && p->zero)
		n += _putchar_(' ');
	while (i++ < p->width)
		n += _putchar_(pad);
	if (neg1 && pad == ' ')
		n += _putchar_('-');
	if (p->plus && !neg2 && pad == ' ' && !p->unsign)
		n += _putchar_('+');
	else if (!p->plus && p->space && !neg2 && !p->unsign && !p->zero)
		n += _putchar_(' ');
	n += _puts_(s);
	return (n);
}

/**
 * print_num_ls - prints an input number
 *             with left shift
 * @s: the input number as string
 * @p: the input struct info
*/
int print_num_ls(char *s, params *p)
{
	unsigned int n = 0;
	unsigned int neg1, neg2;
	unsigned int i = strlen(s);
	char pad = ' ';

	if (p->zero && !p->minus)
		pad = '0';
	neg1 = neg2 = (!p->unsign && *s == '-');
	if (neg1 && i < p->width && pad == '0' && !p->minus)
		s++;
	else
		neg1 = 0;
	if (p->plus && !neg2 && !p->unsign)
	{
		n += _putchar_('+');
		i++;
	}
	else if (p->space && !neg2 && !p->unsign)
	{
		n += _putchar_(' ');
		i++;
	}
	n += puts(s);
	while (i++ < p->width)
		n += _putchar_(pad);
	return (n);
}
