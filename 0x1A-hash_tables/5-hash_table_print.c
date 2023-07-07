#include "hash_tables.h"

/**
 * hash_table_print - this prints a hash table
 * @ht: is pointer to hash table to be printed
 */
void hash_table_print(const hash_table_t *ht)
{
	size_t i = 0, space = 0; /* bool that checks if aux is in a space */
	hash_node_t *aux;

	if (!ht)
		return; 

	printf("{");

	while (i < ht->size)
	{
		aux = ht->array[i];
		while (aux)
		{
			if (space == 1) 
				printf(", ");
			else
				space = 1; /* cuz it will print the pair & the following is a space */
			printf("'%s': '%s'", aux->key, aux->value);
			aux = aux->next;
		}
		i++;
	}

	printf("}\n");
}
