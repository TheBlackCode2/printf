#include "main.h"

/**
 * print_char - prints an input character
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_char(va_list args, params *p)
{
	char cpad = ' ';
	unsigned int pad = 1;
	unsigned int i = 0;
	unsigned int c = va_arg(args, int);

	if (p->minus)
		i += _putchar_(c);
	while(pad++ < p->width)
		i += _putchar_(cpad);
	if(!p->minus)
		i += _putchar_(c);
	return (i);
}

/**
 * print_int - prints an integer
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_int(va_list args, params *p)
{
	long n;

	if (p->l)
		n = va_arg(args, long);
	else if (p->h)
		n = (short int) va_arg(args, int);
	else
		n = (int )va_arg(args, int);
	return (print_num(convert_num(n, 10, 0, p), p));
}

/**
 * print_str - prints a string
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_str(va_list args, params *p)
{
	char cpad = ' ';
	char *s = va_arg(args, char *);
	unsigned int pad = 0;
	unsigned int l = 0, i = 0, j = 0;

	(void)p;
	switch ((int)(!s))
		case 1:
			s = NULL_STR;

	j = pad = getlen(s);
	if (p->precision < pad)
		j = pad = p->precision;

	if(p->minus)
	{
		if (p->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				l += _putchar_(*s++);
		else
			l += _puts_(s);
	}

	while (j++ < p->width)
		l += _putchar_(cpad);

	if (!p->minus)
	{
		if (p->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				l += _putchar_(*s++);
		else
			l += _puts_(s);
	}
	return (l);
}

/**
 * print_percent - prints a percent
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_percent(va_list args, params *p)
{
	(void)args;
	(void)p;
	return (_putchar_('%'));
}

/**
 * print_S - prints a string
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of characters printed
*/
int print_S(va_list args, params *p)
{
	int i = 0;
	char *h;
	char *s = va_arg(args, char *);

	if ((int)(!s))
		return (_puts_(NULL_STR));

	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			i += _putchar_('\\');
			i += _putchar_('x');
			h = convert_num(*s, 16, 0, p);
			if (!h[1])
				i += _putchar_('0');
			i += _puts_(h);
		}
		else
		{
			i += _putchar_(*s);
		}
	}
	return (i);
}
