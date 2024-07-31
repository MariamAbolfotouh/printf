#include "main.h"

/**
 * got_spec - finds the format function
 *
 * @s: the format string
 *
 * Return: number of bytes
 */

int (*got_spec(char *s))(va_list p, parameters_t *parameters)
{
	spec_t specifier[] = {
		{"c", char_print},
		{"s", string_print},
		{"%", percent_print},
		{"d", int_print},
		{"i", int_print},
		{"b", bin_print},
		{"u", unsigned_print},
		{"o", oct_print},
		{"x", hex_print},
		{"X", HEX_print},
		{"S", S_print},
		{"p", address_print},
		{"r", rev_print},
		{"R", rot13_print},
		{NULL, NULL}
	};
	int i = 0;

	while (specifier[i].spec)
	{
		if (*s == specifier[i].spec[0])
		{
			return (specifier[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * got_print - finds format function
 *
 * @s: format string
 * @p: arg pointer
 *
 * Return: num of bytes
 */

int got_print(char *s, va_list p, parameters_t *parameters)
{
	int (*f)(va_list, parameters_t *) = got_spec(s);

	if (f)
	{
		return (f(p, parameters));
	}
	return (0);
}

/**
 * got_flag - find flag function
 *
 * @s: format string
 * @parameters: parameters struct
 *
 * Return: int
 */

int got_flag(char *s, parameters_t *parameters)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = parameters->plus_flag = 1;
			break;
		case ' ':
			i = parameters->space_flag = 1;
			break;
		case '#':
			i = parameters->hashtag_flag = 1;
			break;
		case '0':
			i = parameters->zero_flag = 1;
			break;
		case '-':
			i = parameters->minus_flag = 1;
			break;
	}
	return (i);
}

/**
 * got_modifier - finds mod func
 *
 * @s: format string
 * @parameters: parameters struct
 *
 * Return: int
 */

int got_modifier(char *s, parameters_t *parameters)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = parameters->h_mod = 1;
			break;
		case 'l':
			i = parameters->l_mod = 1;
			break;
	}
	return (i);
}

/**
 * got_width - gets the width
 *
 * @s: format string
 * @parameters: parameters struct
 * @p: pointer to arg
 *
 * Return: pointer
 */

char *got_width(char *s, parameters_t *parameters, va_list p)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(p, int);
		s++;
	}
	else
	{
		while(_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	parameters->width = i;
	return (s);
}
