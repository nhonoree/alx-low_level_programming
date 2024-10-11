#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node, *tmp;

    if (ht == NULL)
        return;

    /* Loop through each index of the hash table */
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];

        /* Delete all nodes in the linked list at this index */
        while (node != NULL)
        {
            tmp = node->next; /* Store the next node */
            free(node->key);  /* Free the key */
            free(node->value);/* Free the value */
            free(node);       /* Free the node itself */
            node = tmp;       /* Move to the next node */
        }
    }

    /* Free the array and the hash table structure */
    free(ht->array);
    free(ht);
}
