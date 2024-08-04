#include "main.h"

/**
 * hex_print - prints unsigned hex num in lowercase
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: bytes
 */

int hex_print(va_list p, params_t *params)
{
	unsigned long i;
	int j = 0;
	char *s;

	if (params->l_mod)
		i = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_mod)
		i = (unsigned short int)va_arg(p, unsigned int);
	else
		i = (unsigned int)va_arg(p, unsigned int);

	s = conv(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && i)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->unsign = 1;
	return (j += num_print(s, params));
}

/**
 * HEX_print - prints unsigned hex num in uppercase
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: bytes
 */

int HEX_print(va_list p, params_t *params)
{
	unsigned long i;
	int j = 0;
	char *s;

	if (params->l_mod)
		i = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_mod)
		i = (unsigned short int)va_arg(p, unsigned int);
	else
		i = (unsigned int)va_arg(p, unsigned int);

	s = conv(i, 16, CONVERT_UNSIGNED , params);
	if (params->hashtag_flag && i)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->unsign = 1;
	return (j += num_print(s, params));
}

/**
 * bin_print - prints unsigned binary num
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: bytes
 */

int bin_print(va_list p, params_t *params)
{
	unsigned int i = va_arg(p, unsigned int);
	char *s = conv(i, 2, CONVERT_UNSIGNED, params);
	int j = 0;

	if (params->hashtag_flag && i)
		*--s = '0';
	params->unsign = 1;
	return (j += num_print(s, params));
}

/**
 * oct_print - prints unsigned octal num
 *
 * @p: pointer to arg
 * @params: parameters struct
 *
 * Return: bytes
 */

int oct_print(va_list p, params_t *params)
{
	unsigned long i;
	char *s;
	int j = 0;

	if (params->l_mod)
		i = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_mod)
		i = (unsigned short int)va_arg(p, unsigned int);
	else
		i = (unsigned int)va_arg(p, unsigned int);
	s = conv(i, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && i)
		*--s = '0';
	params->unsign = 1;
	return (j += num_print(s, params));
}
