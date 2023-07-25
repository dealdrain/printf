#include "main.h"
#include <stdlib.h>

/**
  * _validatechar - type validation
  * @meth: char
  *
  * Return: 1 if char is equal to a type
  */

int _validatechar(char meth)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int p = 0;

	while (_types[p])
	{
		if (_types[p] == meth)
			return (1);
		p++;
	}
	return (0);
}

/**
  * _printfor - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the format
  */
int _printfor(const char *format, va_list args)
{
	int count = 0;
	int x = 0;

	while (format && format[x])
	{
		if (format[x] == '%')
		{
			if (format[x + 1] == '\0')
				return (-1);

			x++;

			while (format[x] == ' ')
				x++;

			if (format[x] == '%')
				count += _pwrite(format[x]);

			if (_validatechar(format[x]) == 0)
			{
				count = _printinvalidspec(format[x - 1], format[x], count);
			}
			else
			{
				count += _printspec(format[x], args);
			}
		}
		else
		{
			count += _pwrite(format[x]);
		}

		x++;
	}

	return (count);
}

/**
  * _printinvalidspec - Print invalid specifier
  * @prev_format: The prev specifier
  * @format: specifier to print
  * @count: current count before print- invalid specifiers
  *
  * Return: current count after prints- invalid specifiers
  */

int _printinvalidspec(char prev_format, char format, int count)
{
	count += _pwrite('%');

	if (prev_format == ' ')
	{
		count += _pwrite(' ');
		count += _pwrite(format);
	}
	else
	{
		count += _pwrite(format);
	}

	return (count);
}

/**
  * _printspec - Print specifier
  * @format: specifier to print
  * @args: list of vari args
  *
  * Return: length of the specifier
  */

int _printspec(char format, va_list args)
{
	int x  = 0, length = 0;
	ald _types[] = {
		{"c", _printchar},
		{"s", _printstr},
		{"d", _printint},
		{"i", _printint},
		{"b", _printintbinary},
		{NULL, NULL}
	};

	while (_types[x].sp)
	{
		if (*_types[x].sp == format)
			length = _types[x].fp(args);

		x++;
	}

	return (length);
}
