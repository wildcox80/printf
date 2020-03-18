#include "holberton.h"

/**
 * check_specifiers - check for a valid format
 * @format: format specifier
 * Return: pointer to valid function or null
 */
static int (*check_specifiers(const char *format))(va_list)
{
	unsigned int i;
	pt p[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_integer},
		{"d", print_decimal},
		{NULL, NULL}
	};

	for (i = 0; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
		{
			break;
		}
	}
	return (p[i].f);
}

/**
 * _printf - prints anything
 * @format: list of arguments passed to the function
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list arg;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = check_specifiers(&format[i + 1]);
		if (f != NULL)
		{
			count += f(arg);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(arg);
	return (count);
}
