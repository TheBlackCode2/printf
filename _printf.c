#include "main.h"

/**
 * _printf - prints formated string
 * @format: the input character string format
 * @...: the input parameters
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int len;
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
		init_params(args, p);
		if (*s1 != '%')
		{
			len += putchar(*s1);
			continue;
		}
		s2 = s1;
		s1++;
		while (get_flag(s1, &p))
			s1++;

		s1 = get_width(s1, args, &p);
		s1 = get_precision(s1, args, &p);

		if (get_modifier(s1, &p))
			s1++;

		if (!get_specifier(s1))
			len += print_ft(s2, s1, ((p.l || p.h) ? (s1 - 1) : 0));
		else len += get_print_function(s1, args, &p);

		s1++;
	}
	putchar(-1);
	va_end(args);
	return (len);
}

/**
 * init_params - clean struct field and
 * @args: the input args list
 * @p: the input struct
 * Return: void
*/
void init_params(va_list args, params *p)
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
 * get_precision - gets precision from input format
 * @s: the input format
 * @args: the input arguments
 * @p: the input struct
*/
char *get_precision(char *s, va_list args, params *p)
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
		while (_isdigit(*s))
			i = i * 10 + (*p++ - '0');
	}
	p->precision = i;
	return (s);
}










