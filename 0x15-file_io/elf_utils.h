#ifndef ELF_UTILS_H
#define ELF_UTILS_H

#include <elf.h>

/* Function prototypes */
void print_magic(Elf64_Ehdr *header);
void print_class(Elf64_Ehdr *header);
/* Add prototypes for other functions */

#endif /* ELF_UTILS_H */
