#include "main.h"

/**
 * get_endianness - this checks the endianness
 *
 * Return: 0 if it is big endian,and 1 if little endian
 */
int get_endianness(void)
{
	unsigned int ui;
	char *c;

	ui = 1;
	c = (char *) &ui;

	return ((int)*c);
}
