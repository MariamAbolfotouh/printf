#include "main.h"

/**
 * got_prec - gets the precision from format str
 *
 * @s: format str
 * @parameters: parameters struct
 * @p: pointer to arg
 *
 * Return: pointer
 */

char *got_prec(char *s, parameters_t *parameters, va_list p)
{
	int i = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		i = va_arg(p, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	parameters->precision = i;
	return (s);
}
