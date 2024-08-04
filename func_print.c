#include "main.h"

/**
 * char_print - print chars
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: num of chars
 */

int char_print(va_list p, params_t *params)
{
	char c = ' ';
	unsigned int pad = 1, count = 0, ch = va_arg(p, int);

	if (params->minus_flag)
		count += _putchar(ch);
	while (pad++ < params->width)
		count += _putchar(c);
	if (!params->minus_flag)
		count += _putchar(ch);
	return (count);
}

/**
 * int_print - print int
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: num of chars
 */

int int_print(va_list p, params_t *params)
{
	long i;

	if (params->l_mod)
		i = va_arg(p, long);
	else if (params->h_mod)
		i = (short int)va_arg(p, int);
	else
		i = (int)va_arg(p, int);
	return (num_print(conv(1, 10, 0, params), params));
}

/**
 * string_print - print string
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: num of chars
 */

int string_print(va_list p, params_t *params)
{
	char *s = va_arg(p, char *), c = ' ';
	unsigned int pad = 0, count = 0, i = 0, j;

	(void)params;
	switch ((int)(!s))
		case 1:
			s = NULL_STRING;

	j = pad = _strlen(s);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				count += _putchar(*s++);
		else
			count += _puts(s);
	}
	while (j++ < params->width)
		count += _putchar(c);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
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
 * @params: parameters struct
 *
 * Return: num of chars
 */

int percent_print(va_list p, params_t *params)
{
	(void)p;
	(void)params;
	return (_putchar('%'));
}

/**
 * S_print - custom format specifier
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: num of chars
 */

int S_print(va_list p, params_t *params)
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
			hex = conv(*s, 16, 0, params);
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
