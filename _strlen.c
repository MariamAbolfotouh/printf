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

	while (*s++)
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
 * @params: parameters struct
 *
 * Return: chars
 */

int num_print(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int j = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (j)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (j)
		*--str = '-';
	if (!params->minus_flag)
		return (num_print_right(str, params));
	else
		return (num_print_left(str, params));
}

/**
 * num_print_right - print num with options
 *
 * @str: base num
 * @params: parameters struct
 *
 * Return: printed chars
 */

int num_print_right(char *str, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(str);
	char c = ' ';

	if (params->zero_flag && !params->minus_flag)
		c = '0';
	n1 = n2 = (!params->unsign && *str == '-');
	if (n1 && i < params->width && c == '0' && !params->minus_flag)
		str++;
	else
		n1 = 0;
	if ((params->plus_flag && !n2) ||
		(!params->plus_flag && params->space_flag && !n2))
		i++;
	if (n1 && c == '0')
		n = n + _putchar('-');
	if (params->plus_flag && !n2 && c == '0' && !params->unsign)
		n = n + _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 &&
		!params->unsign && params->zero_flag)
		n = n + _putchar(' ');
	while (i++ < params->width)
		n += _putchar(c);
	if (n1 && c == ' ')
		n += _putchar('-');
	if (params->plus_flag && !n2 && c == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * num_print_left - print num with options
 *
 * @str: base num
 * @params: parameters struct
 *
 * Return: printed chars
 */

int num_print_left(char *str, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(str);
	char c = ' ';

	if (params->zero_flag && !params->minus_flag)
		c = '0';
	n1 = n2 = (!params->unsign && *str == '-');
	if (n1 && i < params->width && c == '0' && !params->minus_flag)
		str++;
	else
		n1 = 0;
	if (params->plus_flag && !n2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !n2 && !params->unsign)
		n = n + _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(c);
	return (n);
}
