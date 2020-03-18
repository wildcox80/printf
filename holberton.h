#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _printf(char *format, ...);

int ptr_char(va_list ap);
int ptr_str(va_list ap);
int ptr_int(va_list ap);

int pr_rot13(va_list ap);
int pr_rev(va_list ap);
int convert(va_list ap, int base);
int convertU(va_list ap, int base);
int non_prting(va_list ap);
int pr_ptr(va_list ap);

#endif /* HOLBERTON_H */
