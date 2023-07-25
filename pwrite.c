#include <unistd.h>

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
