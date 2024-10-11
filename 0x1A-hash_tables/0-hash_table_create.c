#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	hash_node_t **array;

	hash_table = malloc(sizeof(hash_table_t));  /* No space before '(' */
	if (!hash_table)
		return (NULL);

	array = malloc(sizeof(hash_node_t *) * size);  /* No space before '(' */
	if (!array)
	{
		free(hash_table);  /* No space before '(' */
		return (NULL);
	}

	hash_table->size = size;
	hash_table->array = array;

	return (hash_table);  /* No space before '(' */
}
