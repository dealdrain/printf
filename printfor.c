#include "main.h"
#include <stdlib.h>

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

			if (_validate_char(format[x]) == 0)
			{
				count = _print_invalid_spec(format[x - 1], format[x], count);
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
		{"s", _printstring},
		{"d", _printint},
		{"i", _printint},
		{"b", _printintbinary},
		{NULL, NULL}
	};

	while (_types[x].specifier)
	{
		if (*_types[x].specifier == format)
			length = _types[x].fp(args);

		x++;
	}

	return (length);
}

/**
  * _print_invalid_spec - Print invalid specifier
  * @prev_format: The prev specifier
  * @format: specifier to print
  * @count: current count before print- invalid specifiers
  *
  * Return: current count after prints- invalid specifiers
  */

int _print_invalid_spec(char prev_format, char format, int count)
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
  * _validate_char - type validation
  * @_type: char
  *
  * Return: 1 if char is equal to a type
  */

int _validate_char(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int p = 0;

	while (_types[p])
	{
		if (_types[p] == _type)
			return (1);
		p++;
	}
	return (0);
}
