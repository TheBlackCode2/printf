#include "main.h"

/**
 * get_specifier - find function equivalent
 *                 to the input specifier
 * @s: the input fomat string
 * Return: the number of character printed
*/
int (*get_specifier(char *s))(va_list args, params *p)
{
	specifier sp = 
	{
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned_int},
		{"p", print_adress},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (sp[i].s != NULL && *(sp[i].s) != *s)
		i++;

	return (sp[i].f);
}

/**
 * get_print_function - finds the format function
 * @s: the input format
 * @args: the input arguments
 * @p: the input specifier parameters info
 * Return: the number fo character printed
*/
int get_print_function(char *s, va_list args, params *p)
{
	int (*f)(va_list, params *) = get_specifier(s);

	if (f)
		return (f(args, p));
	return (0);
}

/**
 * get_flag - handle flag
 * @s: the input flag
 * @p: the input specifier parameters info
 * Return: 1 if flag valid
*/
int get_flag(char *s, params *p)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = p->plus = 1;
			break;
		case '-':
			i = p->minus = 1;
			break;
		case ' ':
			i = p->space = 1;
			break;
		case '#':
			i = p->hashtag = 1;
			break;
		case '0':
			i = p->zero = 1;
			break;
	}
	return (i);
}


/**
 * get_modifier - handle modifier
 * @s: the input modifier
 * @p: the input specifier parameters info
 * Return: 1 if modifier valid
*/
int get_modifier(char *s, params *p)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = p->h = 1;
			break;
		case 'l':
			i = p->l = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets formated dtring width
 * @s: the input format
 * @args: the input arguments
 * @p: the input specifier parameters info
 * Return: a pointer
*/
char *get_width(char *s, va_list args, params *p)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(args, int);
		s++;
	}
	else
	{
		while(_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	p->width = i;
	return (s);
}
