#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: character string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;
	int i;

	va_start(arg, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				count = count + write(1, &(va_arg(arg, int)), 1);
			}
			else if (format[i] == 's')
			{
				count = count +
					write(1, &(va_arg(arg, *char)), _strlen(va_arg(arg, *char)));
			}
			else if (format[i] == '%')
			{
				count = count + write(1, '%', 1);
			}
			else
			{
				count = count + write(1, &format[i - 1], 1);
				count = count + write(1, &format[i], 1);
			}
		}
		else
			count = count + write(1, &format[i], 1);
	}
	va_end(arg);
	return (count);
}

/**
 * _strlen - Calculates the length of a string
 *
 * @s: string to be measured
 *
 * Return: the length
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}
