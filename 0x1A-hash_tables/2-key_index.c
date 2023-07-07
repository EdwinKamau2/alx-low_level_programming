#include "hash_tables.h"

/**
 * key_index - this calculates the index of a given key
 * @key: is the key to hash
 * @size: is size of the array
 *
 * Return: index at which the key should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int ind;

	ind = hash_djb2(key); /* hashing */
	return (ind % size);
}
