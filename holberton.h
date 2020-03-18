#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct print_format - structure for print
 * @t: type to print
 * @f: function to print
 */

typedef struct print_format
{
	char *t;
	int (*f)();
} pt;

/**
 * struct flags - Use for Switch the character which represent
 * @plus: character '+'
 * @space: character ' '
 * @hash: characer '#'
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_Validator;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
void print_int_number(va_list l, flags_Validator *f);

#endif
