#include "main.h"

/**
 * _printf - prints formated string
 * @format: the input character string format
 * @...: the input parameters
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int l = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					l += print_char(va_arg(args, int));
					break;

				case 's':
					l += print_str(va_arg(args, char *));
					break;

				case '%':
					l += print_percent();
					break;
			}
			format++;
			continue;
		}

		put_char(*format++);
		l++;
	}

	va_end(args);
	return (l);
}
