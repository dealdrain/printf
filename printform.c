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
	char ex[] = {'c', 's', 'd', 'i', 'b', '%'};
	int p = 0;

	while (ex[p])
	{
		if (ex[p] == meth)
			return (1);
		p++;
	}
	return (0);
}

/**
  * _printform - Prints a format
  * @form: format to print
  * @args: var args
  * Return: form len
  */
int _printform(const char *form, va_list args)
{
	int yes = 0;
	int x = 0;

	while (form && form[x])
	{
		if (form[x] == '%')
		{
			if (form[x + 1] == '\0')
				return (-1);

			x++;

			while (form[x] == ' ')
				x++;

			if (form[x] == '%')
				yes += _pwrite(form[x]);

			if (_validatechar(form[x]) == 0)
			{
				yes = _printinvalidspec(form[x - 1], form[x], yes);
			}
			else
			{
				yes += _printspec(form[x], args);
			}
		}
		else
		{
			yes += _pwrite(form[x]);
		}

		x++;
	}

	return (yes);
}

/**
  * _printinvalidspec - Prints an invalid spec.
  * @old_form: old specifier
  * @format: specifier to print
  * @n: new count pre print
  * Return: current count after prints- invalid specifiers
  */

int _printinvalidspec(char old_form, char format, int n)
{
	n += _pwrite('%');

	if (old_form == ' ')
	{
		n += _pwrite(' ');
		n += _pwrite(format);
	}
	else
	{
		n += _pwrite(format);
	}

	return (n);
}

/**
  * _printspec - Print specifier
  * @format: specifier to print
  * @args: list of vari args
  * Return: specifier len
  */

int _printspec(char format, va_list args)
{
	int x  = 0;
	int len = 0;

	ald ex[] = {
		{"c", _printchar},
		{"d", _printint},
		{"s", _printstr},
		{"i", _printint},
		{"b", _printintbinary},
		{NULL, NULL}
	};

	while (ex[x].sp)
	{
		if (*ex[x].sp == format)
			len = ex[x].fp(args);

		x++;
	}

	return (len);
}
