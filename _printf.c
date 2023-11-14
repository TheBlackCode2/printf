#include "main.h"

/**
 * _printf - prints formated string
 * @format: the input character string format
 * @...: the input parameters
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int len = 0;
	char *s1, *s2;
	va_list args;
	params p = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	s1 = (char *) format;
	while (*s1)
	{
		init_parameters(args, &p);
		if (*s1 != '%')
		{
			len += _putchar_(*s1);
			s1++;
			continue;
		}
		s2 = s1;
		s1++;
		while (flag(s1, &p))
			s1++;

		s1 = width(s1, args, &p);
		s1 = precision(s1, args, &p);

		if (modifier(s1, &p))
			s1++;

		if (!get_specifier(s1))
			len += print_ft(s2, s1, ((p.l || p.h) ? (s1 - 1) : 0));
		else
			len += print_function(s1, args, &p);

		s1++;
	}
	_putchar_(-1);
	va_end(args);
	return (len);
}

/**
 * init_parameters - clean struct field and
 * @args: the input args list
 * @p: the input struct
 * Return: void
*/
void init_parameters(va_list args, params *p)
{
	p->unsign = 0;

	p->plus = 0;
	p->minus = 0;
	p->zero =0;
	p->space = 0;
	p->hashtag = 0;

	p->width = 0;
	p->precision = UINT_MAX;

	p->h = 0;
	p->l = 0;

	(void) args;
}

/**
 * precision - gets precision from input format
 * @s: the input format
 * @args: the input arguments
 * @p: the input struct
*/
char *precision(char *s, va_list args, params *p)
{
	int i = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		i = va_arg(args, int);
		s++;
	}
	else
	{
		while (isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	p->precision = i;
	return (s);
}
