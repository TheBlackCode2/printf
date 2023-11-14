#include "main.h"


/**
 * convert_num - converts function
 * @n: the input number
 * @base: the input base
 * @flags: the input argument flag
 * Return: converyed number as string
*/
char *convert_num(long int n, int base, int flags, params *p)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *s;
	unsigned long num = n;
	(void)p;

	if (!(flags & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		sign = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	s = &buffer[49];
	*s = '\0';

	do
	{
		*--s = arr[num % base];
		num /= base;
	} while (num != 0);

	if (sign)
		*--s = sign;
	return (s);
}

/**
 * print_unsigned_int - prints an input unsigned int
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of printed characters
*/
int print_unsigned_int(va_list args, params *p)
{
	unsigned long i;
	if (p->l)
		i = (unsigned long) va_arg(args, unsigned long);
	else if (p->h)
		i = (unsigned short int) va_arg(args, unsigned int);
	else
		i = (unsigned int) va_arg(args, unsigned int);
	p->unsign = 1;
	return (print_num(convert_num(i, 10, CONVERT_UNSIGNED, p), p));
}

/**
 * print_address - prints an input address
 * @args: the input arguments
 * @p: the input struct info
 * Return: the number of printed characters
*/
int print_address(va_list args, params *p)
{
	unsigned long int n = va_arg(args, unsigned long int);
	char *s;

	if(!n)
		return (puts(NULL_STR));

	s = convert_num(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, p);
	*--s = 'x';
	*--s = '0';

	return (print_num(s, p));
}
