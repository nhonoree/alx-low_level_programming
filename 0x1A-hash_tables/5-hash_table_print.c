#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table
 *
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
    hash_node_t *node;
    unsigned long int i;
    int first = 1;

    if (!ht)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            if (!first)
                printf(", ");
            printf("'%s': '%s'", node->key, node->value);
            first = 0;
            node = node->next;
        }
    }
    printf("}\n");
}
