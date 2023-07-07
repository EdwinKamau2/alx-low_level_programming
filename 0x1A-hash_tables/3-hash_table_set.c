#include "hash_tables.h"

/**
 * add - this inserts a node into a list at the beginning
 * @head: is pointer to the first node
 * @key: is key to add
 * @data: value to add
 *
 * Return: address of the new node,
 * 0 on failure
 */
hash_node_t *add(hash_node_t **head, const char *key, const char *data)
{
	hash_node_t *newNode = NULL;

	newNode = malloc(sizeof(hash_node_t));
	if (!newNode)
		return (0);

	newNode->key = strdup(key);
	newNode->value = strdup(data);
	newNode->next = *head;
	*head = newNode;

	return (newNode);
}

/**
 * hash_table_set - this adds an elements to the hash table
 * @ht: is pointer to the hash table
 * @key: is key to hash
 * @value: value associated with key
 *
 * Return: 1 on success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int ind;
	hash_node_t *aux;

	if (!ht || !key)
		return (0);

	ind = key_index((const unsigned char *)key, ht->size);

	aux = ht->array[ind];
	while (aux)
	{
		if (strcmp(aux->key, key) == 0) /* checks the key */
		{
			free(aux->value), aux->value = strdup(value);
			return (1);
		}
		aux = aux->next; /* moves */
	}
	add(&ht->array[ind], key, value);
	return (1);
}
