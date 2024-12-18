#include "hash_tables.h"

/**
 * key_index - Gives the index of a key
 * @key: The key
 * @size: Size of the array of the hash table
 *
 * Return: Index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}
