#include "holberton.h"

/**
 * _printf - prints a formatted string from input
 * @format: string to be printed
 *
 * Return: length of string
 */
int _printf(const char *format, ...)
{
va_list ap;
int j = 0, k = 0;

va_start(ap, format);

	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			j++;
			while (format[j] == ' ')
				j++;
			if (format[j] == 's')
				k += pr_str(ap);
			else if (format[j] == 'c')
				k += pr_char(ap);
			else if (format[j] == 'd' || format[j] == 'i')
				k += pr_int(ap);
			else if (format[j] == '%')
				write(1, "%", 1);
			else if (format[j] == 'R')
				k += pr_rot13(ap);
			else if (format[j] == 'r')
				k += pr_rev(ap);
			else if (format[j] == 'x')
				k += convert(ap, 16);
			else if (format[j] == 'X')
				k += convertU(ap, 16);
			else if (format[j] == 'o')
				k += convert(ap, 8);
			else if (format[j] == 'b')
				k += convert(ap, 2);
			else if (format[j] == 'S')
				k += non_prting(ap);
			else if (format[j] == 'p')
				k += pr_ptr(ap);
			else
				write(1, &format[j - 1], 2);
		}
		else
		{
		k++;
		write(1, &format[j], 1);
		}
		j++;
	}
	va_end(ap);
	return (k);
}
