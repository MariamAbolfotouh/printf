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
	va_list p;
	int count = 0;
	int i = 0;
	int n;
	char ch;
	char *s;

	va_start(p, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				ch = va_arg(p, int);
				count = count + _putchar(ch);
			}
			else if (format[i] == 's')
			{
				s = va_arg(p, char *);
				count = count + S_print(s);
			}
			else if (format[i] == 'd')
			{
				n = va_arg(p, int);
				count = count + int_print(n);
			}
			else
				count = count + _putchar(format[i]);
		}
		else
			count = count + _putchar(format[i]);
	}

	va_end(p);
	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * S_print - print string
 *
 * @str: string to be printed
 *
 * Return: no. of bytes
 */

int S_print(char *str)
{
	int i = 0, j;

	while (str[i] != '\0')
	{
		j = _putchar(str[i]);
		if (j == -1)
			return (-1);
		i++;
	}
	return (i);
}

/**
 * int_r_print - print integer
 *
 * @n: num to be printed
 *
 * Return: no. of bytes
 */

int int_r_print(int n)
{
	int i = 0, j;

	if (n == 0)
		return (0);
	if (n < 0)
	{
		i = _putchar('-');
		n = n * -1;
	}

	j = int_r_print(n / 10) + 1;
	_putchar('0' + (n % 10));

	return (i + j);
}

/**
 * int_print - print int
 *
 * @n: num to be printed
 *
 * Return: no
 */

int int_print(int n)
{
	if (n == 0)
		return (_putchar('0'));
	return (int_r_print(n));
}
