#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;
	char *s, i;
	parameters_t parameters = PARAMETERS_INITIATION;

	va_start(arg, format);

	if ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (s = (char *)format; *s; s++)
	{
		PARAMETERS_INITIATION(&parameters, arg);
		if (*s != '%')
		{
			count = count + _putchar(*s);
			continue;
		}
		i = s;
		s++;
		while (got_flag(s, &parameters))
		{
			s++;
		}
		if (!got_spec(s))
			count = count + from_to(i, s, parameters.l_mod || 
				parameters.h_mod ? s - 1 : 0);
		else
			count = count + got_print(s, arg, &parameters);
	}
	_putchar(buffer_flush);
	va_end(arg);
	return (count);
}

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

	while (s[len])
		len++;
	return (len);
}
