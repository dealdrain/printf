#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * _printint - Prints an int
  * @args: args list
  * Return: str len
  */

int _printint(va_list args)
{
	int count = 1;
	int j = 0;
	unsigned int g = 0;

	g = va_arg(args, int);
	j = g;
	if (j < 0)
	{
		_pwrite('-');
		j = j * -1;
		g = j;
		count += 1;
	}
	while (g > 9)
	{
		g = g / 10;
		count++;
	}

	_recursionint(j);
	return (count);
}

/**
  * _printchar - func to Printng a char
  * @args: args list
  * Return: char length. (1) always
  */

int _printchar(va_list args)
{
	_pwrite(va_arg(args, int));
	return (1);
}

/**
  * _printstring - Print a str
  * @args: args list
  * Return: str len
  */

int _printstring(va_list args)
{
	char *arg = va_arg(args, char *);
	int x = 0;

	if (arg != NULL)
	{
		while (arg[x])
		{
			_pwrite(arg[x]);
			x++;
		}

		return (x);
	}

	_pwrite('(');
	_pwrite('n');
	_pwrite('u');
	_pwrite('l');
	_pwrite('l');
	_pwrite(')');
	return (6);
}
