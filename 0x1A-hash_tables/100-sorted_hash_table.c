#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of the array
 *
 * Return: Pointer to the newly created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: Key string
 * @value: Value string
 *
 * Return: 1 if successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *tmp;
	char *value_copy;
	unsigned long int index;

	if (!ht || !key || !*key || !value)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(value_copy);
		free(new_node);
		return (0);
	}
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	insert_sorted_list(ht, new_node);
	return (1);
}

/**
 * insert_sorted_list - Inserts a node into the sorted linked list
 * @ht: The hash table
 * @node: The new node to insert
 */
void insert_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		node->sprev = NULL;
		node->snext = NULL;
		return;
	}

	tmp = ht->shead;
	while (tmp && strcmp(node->key, tmp->key) > 0)
		tmp = tmp->snext;

	if (tmp == NULL)  /* Insert at the end */
	{
		ht->stail->snext = node;
		node->sprev = ht->stail;
		ht->stail = node;
		node->snext = NULL;
	}
	else if (tmp == ht->shead) /* Insert at the beginning */
	{
		node->snext = ht->shead;
		node->sprev = NULL;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else /* Insert in the middle */
	{
		node->sprev = tmp->sprev;
		node->snext = tmp;
		tmp->sprev->snext = node;
		tmp->sprev = node;
	}
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: Pointer to the sorted hash table
 * @key: Key string
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table in order
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	printf("{");
	node = ht->shead;
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	printf("{");
	node = ht->stail;
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: Pointer to the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (!ht)
		return;

	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(ht->array);
	free(ht);
}
