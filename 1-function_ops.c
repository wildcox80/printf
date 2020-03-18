#include "holberton.h"

/**
 * convert - changes a number to hexadecimal in lowercas
 * @ap: va_list at location of thing that needs to be printed
 * @base: base to be changed to
 *
 * Return: length of number
 */
int convert(va_list ap, int base)
{
	unsigned int dec_num = va_arg(ap, unsigned int);
	char buffer[2];
	int hex_num[50], i, j;

	buffer[1] = '\0';
	i = 0;
	while (dec_num)
	{
		hex_num[i] = dec_num % base;
		dec_num = dec_num / base;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (hex_num[j] <= 9)
		{
			buffer[0] = hex_num[j] + '0';
			write(1, buffer, 1);
		}
		else
		{
			buffer[0] = hex_num[j] + 87;
			write(1, buffer, 1);
		}
	}
	return (i);
}

/**
 * convertU -  function to convert dec to HEX in UPPERCASE
 * @ap: va_list at location of thing that needs to be printed
 * @base: int type
 *
 * Return: length of number
 */
int convertU(va_list ap, int base)
{
	unsigned int dec_num = va_arg(ap, unsigned int);
	char buffer[2];
	int hex_num[50], i, j;

	buffer[1] = '\0';
	i = 0;
	while (dec_num)
	{
		hex_num[i] = dec_num % base;
		dec_num = dec_num / base;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (hex_num[j] <= 9)
		{
			buffer[0] = hex_num[j] + '0';
			write(1, buffer, 1);
		}
		else
		{
			buffer[0] = hex_num[j] + 55;
			write(1, buffer, 1);
		}
	}
	return (i);
}

/**
 * non_prting - replaces non-printing characters with "\x" and ascii value
 * @ap: va_list at location of thing that needs to be printed
 *
 * Return: length of string
 */
int non_prting(va_list ap)
{
	char *str = va_arg(ap, char *);
	char buffer[2];
	int hex_num[50], i = 0, j, k = 0, dec_num, base = 16;

	buffer[1] = '\0';
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			write(1, "\\x", 2);
			dec_num = (int)(*str);
			if (dec_num < 16)
				write(1, "0", 1);
			while (dec_num)
			{
				hex_num[i] = dec_num % base;
				dec_num = dec_num / base;
				i++;
			}
			for (j = i - 1; j >= 0; j--)
			{
				if (hex_num[j] <= 9)
				{
					buffer[0] = hex_num[j] + '0';
					write(1, buffer, 1);
				}
				else
				{
					buffer[0] = hex_num[j] + 55;
					write(1, buffer, 1);
				}
			}
		}
		else
			write(1, str, 1);
		str++;
		k++;
	}

	return (k);
}

/**
 * pr_ptr - prints the address of a pointer
 * @ap: va_list at location of thing that needs to be printed
 *
 * Return: length of address
 */
int pr_ptr(va_list ap)
{
	void *ptr = va_arg(ap, void *);
	unsigned long int dec_num = (unsigned long int)ptr;
	char buffer[2];
	int hex_num[50], i, j, base = 16;

	write(1, "0x", 2);
	buffer[1] = '\0';
	i = 0;
	while (dec_num)
	{
		hex_num[i] = dec_num % base;
		dec_num = dec_num / base;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (hex_num[j] <= 9)
		{
			buffer[0] = hex_num[j] + '0';
			write(1, buffer, 1);
		}
		else
		{
			buffer[0] = hex_num[j] + 55;
			write(1, buffer, 1);
		}
	}
	return (i);
}
