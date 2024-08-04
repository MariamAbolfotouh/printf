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
	va_list arg;
	int count = 0;
	char *s, *i;
	params_t params = PARAMETERS_INITIATION;

	va_start(arg, format);

	if ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (s = (char *)format; *s; s++)
	{
		parameters_initial(&params, arg);
		if (*s != '%')
		{
			count = count + _putchar(*s);
			continue;
		}
		i = s;
		s++;
		while (got_flag(s, &params))
		{
			s++;
		}
		s = got_width(s, &params, arg);
		s = got_prec(s, &params, arg);
		if (!got_modifier(s, &params))
			s++;
		if (!got_spec(s))
			count = count + from_to(i, s, params.l_mod ||
				params.h_mod ? s - 1 : 0);
		else
			count = count + got_print(s, arg, &params);
	}
	_putchar(buffer_flush);
	va_end(arg);
	return (count);
}
