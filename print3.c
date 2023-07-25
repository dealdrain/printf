#include "main.h"

/**
 * convert - convert num & bases to str
 * @number: input no.
 * @ib: input base
 * @lcase: flag if hexa values need to be lowercase
 * Return: result string
 */

char *convert(unsigned long int number, int ib, int lcase)
{
	static char *loe;
	static char buffer[50];
	char *y;

	loe = (lcase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	y = &buffer[49];
	*y = '\0';
	do {
		*--y = loe[number % ib];
		number /= ib;
	} while (number != 0);

	return (y);
}
