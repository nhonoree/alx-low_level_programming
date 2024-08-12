#include <stdio.h>
#include "elf_utils.h"

int main(int argc, char *argv[])
{
	(void)argc; /* To avoid unused parameter warning */
	(void)argv; /* To avoid unused parameter warning */

    /* Your existing code */
       
	return (0); /* Return statement with parentheses */
}

void print_elf_header(Elf64_Ehdr *header)
{
    /* Use the functions from elf_utils.c */
	print_magic(header);
	print_class(header);
    /* Call other functions */
}
