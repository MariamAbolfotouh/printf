#include "main.h"

/**
 * from_to - print range of char addresses
 *
 * @from: from address
 * @to: to address
 * @except: except address
 *
 * Return: num of bytes
 */

int from_to(char *from, char *to, char *except)
{
	int count = 0;

	while (from <= to)
	{
		if (from != except)
			count = count + _putchar(*from);
		from++;
	}
	return (count);
}

/**
 * rev_print - reverse the str
 *
 * @p: string
 * @parameters: parameters struct
 *
 * Return: num of bytes
 */

int rev_print(va_list p, parameters_t *parameters)
{
	int i, count = 0;
	char *s = va_arg(p, char *);
	(void)parameters;

	if (s)
	{
		for (i = 0, *s; s++)
			i++;
		s--;
		for (; i > 0; i--, s--)
			count = count + _putchar(*str);
	}
	return (count);
}

/**
 * rot13_print - print str in rot13
 *
 * @p: string
 * @parameters: parameters sstruct
 *
 * Return: num of bytes
 */

int rot13_print(va_list p, parameters_t *parameters)
{
	int i, n;
	int count = 0;
	char a[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(p, char *);
	(void)parameters;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((s[i] >= 'A' && s[i] <= 'Z')
			|| (s[i] >= 'a' && s[i] <= 'z'))
		{
			n = s[i] - 65;
			count = count + _putchar(a[n]);
		}
		else
			count = count + _putchar(s[i]);
		i++;
	}
	return (count);
}
