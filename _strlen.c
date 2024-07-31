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
	if (parameters->precision != UNIT_MAX)
		while (i++ < parameters->precision)
			*--str= '0';
	if (j)
		*--str = '-';
	if (!parameters->minus_flag)
		return (num_print_right(str, parameters));
	else
		return (num_print_left(str, parameters));
}
