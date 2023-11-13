#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define NULL_STR "(null)"

/**
 * struct specifier_params - specifier parameters struct
 * @unsign: specified if it's unsigned value
 * @plus: checks for plus flag
 * @minus: checks for minus flag
 * @zero: cheks for zero flag
 * @space: checks for space flag
 * @hashtag: checks for hashtag flag
 * @width: field width
 * @precision: field precision
 * @h: specified h modifier
 * @l: specified l modifier
*/
typedef struct specifier_params
{
	unsigned int unsign;
	unsigned int plus;
	unsigned int minus;
	unsigned int zero;
	unsigned int space;
	unsigned int hashtag;

	unsigned int width;
	unsigned int precision;

	unsigned int h;
	unsigned int l;
} params;

/**
 * struct specifier - specifier info struct
 * @s: the input specifier
 * @f: access function
*/
struct specifier
{
	char *s;
	int (*f)(va_list, params)
}

/* puts.c module */
int puts(char *s);
int putchar(int c);

/* print_type.c module */
int print_char(va_list args, params *p);
int print_int(va_list args, params *p);
int print_string(va_list args, params *p);
int print_percent(va_list args, params *p);
int print_S(va_list args, params *p);

/* print_adress.c module */
char *convert(long int n, int base, int flags);
int print_unsigned_int(va_list args, params *p);
int print_adress(va_list args, params *p);

/* specifier.c module */
int (*get_specifier(char *s))(va_list args, params *p);
int get_print_function(char *s, va_list, args, params *p);
int get_flag(char *s, params *p);
int get_modifier(char *s, params *p);
char *get_width(char *s, va_list args, params *p);

/* print_converted_num.c module*/
int print_hex(va_list args, params *p);
int print_HEX(va_list args, params *p);
int print_binary(va_list args, params *p);
int print_octal(va_list args, params *p);

/* print_mod.c module */
int print_ft(char *start, char *end, char *e);
int print_rev(va_list args, params *p);
int print_rot13(va_list, params *p);

/* print_num.c module */
int is_digit(int c);
int strlen(char *s);
int print_num(char *s, params *p);
int print_num_rs(char *s params);
int print_num_ls(char *s params);

/* _print.c module */
void init_params(va_list args, params *p);
char *get_precision(char *s, va_list args, params *p);
int _printf(const char *format, ...);

#endif /* MAIN_H */
