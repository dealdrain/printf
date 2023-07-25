#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * _print_int_binary - Print int to binary
  * @args: list of args
  * Return: printed int
  */
int _printintbinary(va_list args)
{
	unsigned int g = 0;
	int e = 0;
	int j = 0;

	j = va_arg(args, int);
	g = j;
	if (j < 0)
	{
		_pwrite('1');
		j = j * -1;
		g = j;
		e += 1;
	}
	while (g > 0)
	{
		g = g / 2;
		e++;
	}
	_recursionintbinary(j);
	return (e);
}

/**
  * _recursionintbinary - Print a binary
  * @a: int
  */
void _recursionintbinary(int a)
{
	unsigned int z;

	z = a;
	if (z / 2)

		_recursionintbinary(z / 2);
	
	_pwrite(z % 2 + '0');
}
