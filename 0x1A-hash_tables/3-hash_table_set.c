#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table
 * @key: The key, cannot be empty
 * @value: The value associated with the key, must be duplicated
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node, *temp;
    unsigned long int index;

    if (!ht || !key || !value || strlen(key) == 0)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    temp = ht->array[index];

    while (temp)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = strdup(value);
            return (1);
        }
        temp = temp->next;
    }

    new_node = malloc(sizeof(hash_node_t));
    if (!new_node)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}