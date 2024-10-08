#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: name to be printed
 * @f: function pointer to a function that prints the name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
