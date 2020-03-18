#include "holberton.h"

/**
 * pr_char - prints a character
 * @ap: va_list at location of thing that needs to be printed
 *
 * Return: length of char
 */
int pr_char(va_list ap)
{
	char c_hold = (char)va_arg(ap, int);

	write(1, &c_hold, 1);

	return (1);
}

/**
 * pr_str - prints a string
 * @ap: va_list at location of thing that needs to be printed
 *
 * Return: length of string
 */
int pr_str(va_list ap)
{
	char *c_ptr = va_arg(ap, char *);
	int i = 0;

	if (c_ptr == NULL)
		return (0);
	while (*c_ptr != '\0')
	{
		write(1, c_ptr, 1);
		c_ptr++;
		i++;
	}

	return (i);
}

/**
 * pr_int - prints an int
 * @ap: va_list at location of thing that needs to be printed
 *
 * Return: length of int
 */
int pr_int(va_list ap)
{
	int i = va_arg(ap, int), j = 1000000000, digit, _bool = 0, k = 0;
	char buffer[2] = {'0', '\0'};

	if (i == INT_MIN)
	{
		i++;
		_bool = 1;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (i / j < 1)
	{
		j = j / 10;
	}
	while (i > 0)
	{
		k++;
		digit = i / j;
		i = i % j;
		j = j / 10;
		buffer[0] = digit + '0';
		if (_bool == 1)
			i++;
		_bool = 0;
		write(1, buffer, 1);
	}
	if (i == 0 && j == 1)
	{
		k++;
		write(1, "0", 1);
	}
	return (k);
}

/**
 * pr_rot13 - converts a string to rot13
 * @ap: va_list at location of thing that needs to be printed
 *
 * Return: length of string
 */
int pr_rot13(va_list ap)
{
	char *c_ptr = va_arg(ap, char *);
	char buffer[300];
	char *count = buffer;
	int i = 0;

	if (c_ptr == NULL)
		return (0);
	while (*c_ptr != '\0')
	{
		if (*c_ptr >= 'a' && *c_ptr <= 'm')
			*count = *c_ptr + 13;
		else if (*c_ptr >= 'A' && *c_ptr <= 'M')
			*count = *c_ptr + 13;
		else if (*c_ptr >= 'n' && *c_ptr <= 'z')
			*count = 'a' + (*c_ptr - 'n');
		else if (*c_ptr >= 'N' && *c_ptr <= 'Z')
			*count = 'A' + (*c_ptr - 'N');
		c_ptr++;
		count++;
	}
	*count = '\0';
	count = buffer;
	while (*count != '\0')
	{
		i++;
		write(1, count, 1);
		count++;
	}

	return (i);
}

/**
 * pr_rev - prints string in reverse
 * @ap: va_list at location of thing that needs to be printed
 *
 * Return: length of string
 */
int pr_rev(va_list ap)
{
	char *c_ptr = va_arg(ap, char *);
	char *start = c_ptr;
	int i = 0;

	if (c_ptr == NULL)
		return (0);
	while (*c_ptr != '\0')
	{
		i++;
		c_ptr++;
	}
	while (c_ptr > start)
	{
		write(1, c_ptr, 1);
		c_ptr--;
	}
	write(1, c_ptr, 1);

	return (i);
}
