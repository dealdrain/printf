#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - function printf
 * @format: string format to print
 *
 * Return: no. of chars that print
 */

int _printf(const char *format, ...)
{
	va_list args;
	int x;

	x = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	x = _print_format(format, args);

	va_end(args);

	return (x);
}
