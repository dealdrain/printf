#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
  * _recursionint - Print int
  * @e: int to print
  *
  * Return: Nothing
  */

void _recursionint(int e)
{
	unsigned int uc;

	uc = e;

	if (uc / 10)
		_recursionint(uc / 10);
	_pwrite(uc % 10 + '0');
}


/**
  * _recursionintbinary - Print a binary
  * @l: int
  */
void _recursionintbinary(int l)
{
	unsigned int z;

	z = l;
	if (z / 2)

		_recursionintbinary(z / 2);

	_pwrite(z % 2 + '0');
}

/**
  * _printintbinary - Print int to binary
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
 * _pwrite - write char k
 * @k: char to print
 *
 * Return: 1 if good. else -1
 */

int _pwrite(char k)
{
	return (write(1, &k, 1));
}
