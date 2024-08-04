#include "main.h"

/**
 * char_print - print chars
 *
 * @p: pointer to arg
 * @parameters: parameters struct
 *
 * Return: num of chars
 */

int char_print(va_list p, parameters_t *parameters)
{
	char c = ' ';
	unsigned int pad = 1, count = 0, ch = va_arg(p, int);

	if (parameters->minus_flag)
		count += _putchar(ch);
	while (pad++ < parameters->width)
		count += _putchar(c);
	if (!parameters->minus_flag)
		count += _putchar(ch);
	return (count);
}

/**
 * int_print - print int
 *
 * @p: pointer to arg
 * @parameters: parameters struct
 *
 * Return: num of chars
 */

int int_print(va_list p, parameters_t *parameters)
{
	long i;

	if (parameters->l_mod)
		i = va_arg(p, long);
	else if (parameters->h_mod)
		i = (short int)va_arg(p, int);
	else
		i = (int)va_arg(p, int);
	return (num_print(conv(1, 10, 0, parameters), parameters));
}

/**
 * string_print - print string
 *
 * @p: pointer to arg
 * @parameters: parameters struct
 *
 * Return: num of chars
 */

int string_print(va_list p, parameters_t *parameters)
{
	char *s = va_arg(p, char *), c = ' ';
	unsigned int pad = 0, count = 0, i = 0, j;

	(void)parameters;
	switch ((int)(!s))
		case 1:
			s = NULL_STRING;
	
	j = pad = _strlen(s);
	if (parameters->precision < pad)
		j = pad = parameters->precision;

	if (parameters->minus_flag)
	{
		if (parameters->precision != UNIT_MAX)
			for (i = 0; i < pad; i++)
				count += _putchar(*s++);
		else
			count += _puts(s);
	}
	while (j++ < parameters->width)
		count += _putchar(c);
	if (!parameters->minus_flag)
	{
		if (parameters->precision != UNIT_MAX)
			for (i = 0; i < pad; i++)
				count += _putchar(*s++);
		else
			count += _puts(s);
	}
	return (count);
}

/**
 * percent_print - print percent
 *
 * @p: pointer to arg
 * @parameters: parameters struct
 *
 * Return: num of chars
 */

int percent_print(va_list p, parameters_t *parameters)
{
	(void)p;
	(void)parameters;
	return (_putchar('%'));
}

/**
 * S_print - custom format specifier
 *
 * @p: pointer to arg
 * @parameters: parameters struct
 *
 * Return: num of chars
 */

int S_print(va_list p, parameters_t *parameters)
{
	char *s = va_arg(p, char *);
	char *hex;
	int count = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hex = conv(*s, 16, 0, parameters);
			if (!hex[1])
				count += _putchar('0');
			count += _puts(hex);
		}
		else
		{
			count += _putchar(*s);
		}
	}
	return (count);
}
