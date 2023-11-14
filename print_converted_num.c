#include "main.h"

/**
 * print_hex_num - prints hex number in lowercase
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_hex_num(va_list args, params *p)
{
	unsigned long  l;
	int i = 0;
	char *s;

	if (p->l)
		l = (unsigned long) va_arg(args, unsigned long);
	else if (p->h)
		l = (unsigned short int) va_arg(args, unsigned int);
	else
		l = (unsigned int) va_arg(args, unsigned int);
	s = convert_num(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, p);
	if (p->hashtag && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	p->unsign = 1;
	i += print_num(s, p);
	return (i);
}


/**
 * print_HEX_num - prints hex number in uppercase
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_HEX_num(va_list args, params *p)
{
	unsigned long  l;
	int i = 0;
	char *s;

	if (p->l)
		l = (unsigned long) va_arg(args, unsigned long);
	else if (p->h)
		l = (unsigned short int) va_arg(args, unsigned int);
	else
		l = (unsigned int) va_arg(args, unsigned int);
	s = convert_num(l, 16, CONVERT_UNSIGNED, p);
	if (p->hashtag && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	p->unsign = 1;
	i += print_num(s, p);
	return (i);
}

/**
 * print_binary_num - prints binary number
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_binary_num(va_list args, params *p)
{
	unsigned int l = va_arg(args, unsigned int);
	int i = 0;
	char *s = convert_num(l, 2, CONVERT_UNSIGNED, p);

	if (p->hashtag && l)
		*--s = '0';
	p->unsign = 1;
	i += print_num(s, p);
	return (i);
}

/**
 * print_octal_num - prints octal number
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_octal_num(va_list args, params *p)
{
	unsigned long  l;
	int i = 0;
	char *s;

	if (p->l)
		l = (unsigned long) va_arg(args, unsigned long);
	else if (p->h)
		l = (unsigned short int) va_arg(args, unsigned int);
	else
		l = (unsigned int) va_arg(args, unsigned int);
	s = convert_num(l, 8, CONVERT_UNSIGNED, p);
	if (p->hashtag && l)
		*--s = '0';
	p->unsign = 1;
	i += print_num(s, p);
	return (i);
}
