#include "hash_tables.h"

/**
 * hash_table_get - this retrieves a value associated with a key
 * @ht: is pointer to hash table
 * @key: key
 *
 * Return: the key if it exists, NULL if not
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *check_key; /* aux pointer */
	unsigned long int ind;

	if (!ht || !key)
		return (NULL);

	ind = key_index((const unsigned char *)key, ht->size);

	check_key = ht->array[ind];
	while (check_key)
	{
		if (strcmp(check_key->key, key) == 0) /* if  requested key exists */
			return (check_key->value); /* returns value associated at the key */
		check_key = check_key->next;
	}

	return (NULL);
}
