#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table with a given size
 * @size: size of the hash table
 *
 * Return: pointer to the hash table or 
 * NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_Table;

	new_Table = malloc(sizeof(hash_table_t));
	if (!new_Table)
		return (NULL);

	new_Table->size = size;
	/* new_Table->size = length, hash_node_t * = size of elements */
	new_Table->array = calloc(new_Table->size, sizeof(hash_node_t *));
	if (!new_Table->array)
		return (NULL);

	return (new_Table);
}
