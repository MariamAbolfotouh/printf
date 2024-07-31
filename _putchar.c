#include "main.h"

/**
 * _putchar - writes char c to the stdout
 *
 * @c: the char to be printed
 *
 * Return: on success 1
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(int c)
{
	static int j;
	static char buffer[op_buffer_size];

	if (c == buffer_flush || j >= op_buffer_size)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (c != buffer_flush)
	{
		buffer[j++] = c;
	}
	return (1);
}

/**
 * _puts - prints str with newline
 *
 * @str: string to be printed
 *
 * Return: str - s
 */

int _puts(char *str)
{
	char *s = str;

	while (*str)
	{
		_putchar(*str++);
	}
	return (str - s);
}
