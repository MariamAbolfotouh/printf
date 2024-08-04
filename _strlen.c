#include "main.h"

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

	while(*s++)
	{
		len++;
	}

	return (len);
}

/**
 * _isdigit - checks if char is digit
 *
 * @c: char to be checked
 *
 * Return: 1 if digit
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * num_print - print num
 *
 * @str: num as str
 * @parameters: parameters struct
 *
 * Return: chars
 */

int num_print(char *str, parameters_t *parameters)
{
	unsigned int i = _strlen(str);
	int j = (!parameters->unsign && *str == '-');

	if (!parameters->precision && *str == '0' && !str[1])
		str = "";
	if (j)
	{
		str++;
		i--;
	}
	if (parameters->precision != UINT_MAX)
		while (i++ < parameters->precision)
			*--str= '0';
	if (j)
		*--str = '-';
	if (!parameters->minus_flag)
		return (num_print_right(str, parameters));
	else
		return (num_print_left(str, parameters));
}

/**
 * num_print_right - print num with options
 *
 * @str: base num
 * @parameters: parameters struct
 *
 * Return: printed chars
 */

int num_print_right(char *str, parameters_t *parameters)
{
	unsigned int n = 0, n1, n2, i = _strlen(str);
	char c = ' ';

	if (parameters->zero_flag && !parameters->minus_flag)
		c = '0';
	n1 = n2 = (!parameters->unsign && *str == '-');
	if (n1 && i < parameters->width && c == '0' && !parameters->minus_flag)
		str++;
	else
		n1 = 0;
	if ((parameters->plus_flag && !n2) ||
		(!parameters->plus_flag && parameters->space_flag && !n2))
		i++;
	if (n1 && c == '0')
		n = n + _putchar('-');
	if (parameters->plus_flag && !n2 && c == '0' && !parameters->unsign)
		n = n + _putchar('+');
	else if (!parameters->plus_flag && parameters->space_flag && !n2 &&
		!parameters->unsign && parameters->zero_flag)
		n = n + _putchar(' ');
	while (i++ < parameters->width)
		n += _putchar(c);
	if (n1 && c == ' ')
		n += _putchar('-');
	if (parameters->plus_flag && !n2 && c == ' ' && !parameters->unsign)
		n += _putchar('+');
	else if (!parameters->plus_flag && parameters->space_flag && !n2 &&
		!parameters->unsign && !parameters->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * num_print_left - print num with options
 *
 * @str: base num
 * @parameters: parameters struct
 *
 * Return: printed chars
 */

int num_print_left(char *str, parameters_t *parameters)
{
	unsigned int n = 0, n1, n2, i = _strlen(str);
	char c = ' ';

	if (parameters->zero_flag && !parameters->minus_flag)
		c = '0';
	n1 = n2 = (!parameters->unsign && *str == '-');
	if (n1 && i < parameters->width && c == '0' && !parameters->minus_flag)
		str++;
	else
		n1 = 0;
	if (parameters->plus_flag && !n2 && !parameters->unsign)
		n += _putchar('+'), i++;
	else if (parameters->space_flag && !n2 && !parameters->unsign)
		n = n + _putchar(' '), i++;
	n += _puts(str);
	while (i++ < parameters->width)
		n += _putchar(c);
	return (n);
}
