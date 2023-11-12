#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED __attribute__((unused))

/**
 * specifier_attr - a struct for given specifier props
 * @width: the input width
 * @precision: the input precision
 * @length: the input length
*/
typedef struct specifier_attr
{
	int width;
	int precision;
	int length;
} specifier_t;

int puts(const char *s);
int put_char(int c);

int print_char(char c);
int print_percent(void);

int print_str(const char *s);
int print_S(const char *s);
int print_rev(const char *s);
int print_rot13(const char *s);

int print_int(int i);
int print_unsigned_int(unsigned int u);
int print_binary(int b);
int print_octal(int o);
int print_hex(int h);
int print_HEX(int h);

int print_adress(void *p);

int _printf(const char *format, ...);

#endif /* MAIN_H */
