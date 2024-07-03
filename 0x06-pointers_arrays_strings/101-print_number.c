#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */
void print_number(int n)
{
    unsigned int num;

    if (n < 0) {
        _putchar('-');
        num = (unsigned int)(-n);  // Convert negative n to unsigned int
    } else {
        num = (unsigned int)n;
    }

    if (num / 10 != 0) {
        print_number(num / 10);  // Recursive call to print digits recursively
    }

    _putchar((num % 10) + '0');  // Print each digit
}
