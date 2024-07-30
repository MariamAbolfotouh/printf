#include <stdio.h>
#include "main.h"

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

	while(*s++)
	{
		len++;
	}

	return (len);
}
