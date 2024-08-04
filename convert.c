#include "main.h"

/**
 * conv - converter function
 *
 * @number: num
 * @base: base
 * @flag: arg flags
 * @params: parameters struct
 *
 * Return: str
 */

char *conv(long int number, int base, int flag, params_t *params)
{
	static char *arr;
	static char buf[50];
	char *p;
	char sign = 0;
	unsigned long l = number;
	(void)params;

	if (!(flag & CONVERT_UNSIGNED) && number < 0)
	{
		l = -number;
		sign = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do {
		*--p = arr[l % base];
		l /= base;
	} while (l != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * unsigned_print - print unsigned integers numbs
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: bytes
 */

int unsigned_print(va_list p, params_t *params)
{
	unsigned long l;

	if (params->l_mod)
		l = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(p, unsigned int);
	else
		l = (unsigned int)va_arg(p, unsigned int);
	params->unsign = 1;
	return (num_print(conv(1, 10, CONVERT_UNSIGNED, parameters), parameters));
}

/**
 * address_print - print address
 *
 * @p: pointer to arg
 * @parameters: parameters struct
 *
 * Return: bytes
 */

int address_print(va_list p, parameters_t *parameters)
{
	unsigned long int i = va_arg(p, unsigned long int);
	char *s;

	if (!i)
		return (_puts("(nil)"));

	s = conv(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, parameters);
	*--s = 'x';
	*--s = '0';
	return (num_print(s, parameters));
}
