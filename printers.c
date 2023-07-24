#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * _print_a_char - Prints a char
  * @args: A list of variadic arguments
  *
  * Return: The length of the character
  */

int _print_a_char(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}

/**
  * _print_a_string - Prints a string
  * @args: list of var arguments
  *
  * Return: The length of the string
  */

int _print_a_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int x = 0;

	if (arg != NULL)
	{
		while (arg[x])
		{
			_write(arg[x]);
			x++;
		}

		return (x);
	}

	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}

/**
  * _print_a_integer - Print integer
  * @args: list of variadic args
  *
  * Return: The length of the string
  */

int _print_a_integer(va_list args)
{
	int count = 1, m = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;
	if (m < 0)
	{
		_write('-');
		m = m * -1;
		n = m;
		count += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}

	_recursion_integer(m);
	return (count);
}

/**
  * _recursion_integer - Print int
  * @a: int to print
  *
  * Return: Nothing
  */

void _recursion_integer(int a)
{
	unsigned int c;

	c = a;
	if (c / 10)
		_recursion_integer(c / 10);
	_write(c % 10 + '0');
}
