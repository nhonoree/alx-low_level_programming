#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table
 * @key: The key to find
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *temp;
    unsigned long int index;

    if (!ht || !key || strlen(key) == 0)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    temp = ht->array[index];

    while (temp)
    {
        if (strcmp(temp->key, key) == 0)
            return (temp->value);
        temp = temp->next;
    }

    return (NULL);
}
