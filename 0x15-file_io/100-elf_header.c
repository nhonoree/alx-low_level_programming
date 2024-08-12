#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

#define BUF_SIZE 64

void print_error(const char *message, const char *filename, int exit_code)
{
    if (filename)
        dprintf(STDERR_FILENO, message, filename);
    else
        dprintf(STDERR_FILENO, "%s", message);
    exit(exit_code);
}

void print_elf_header_info(const Elf64_Ehdr *header)
{
    // Print Magic number
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", header->e_ident[i], (i < EI_NIDENT - 1) ? ' ' : '\n');

    // Print Class
    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %02x>\n", header->e_ident[EI_CLASS]);
        break;
    }

    // Print Data
    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %02x>\n", header->e_ident[EI_DATA]);
        break;
    }

    // Print Version
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    // Print OS/ABI
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    default:
        printf("<unknown: %02x>\n", header->e_ident[EI_OSABI]);
        break;
    }

    // Print ABI Version
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    // Print Type
    printf("  Type:                              ");
    switch (header->e_type)
    {
    case ET_NONE:
        printf("NONE (Unknown type)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %02x>\n", header->e_type);
        break;
    }

    // Print Entry point address
    printf("  Entry point address:               ");
    if (header->e_ident[EI_CLASS] == ELFCLASS64)
        printf("0x%lx\n", (unsigned long)header->e_entry);
    else
        printf("0x%x\n", (unsigned int)header->e_entry);
}

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;
    ssize_t bytes_read;

    if (argc != 2)
        print_error("Usage: %s elf_filename\n", NULL, 97);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error("Error: Can't read from file %s\n", argv[1], 98);

    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read < 0)
        print_error("Error: Can't read from file %s\n", argv[1], 98);
    if (bytes_read < sizeof(header))
        print_error("Error: File %s is too short\n", argv[1], 98);

    if (header.e_ident[EI_MAG0] != 0x7f ||
        header.e_ident[EI_MAG1] != 'E' ||
        header.e_ident[EI_MAG2] != 'L' ||
        header.e_ident[EI_MAG3] != 'F')
        print_error("Error: Not an ELF file - %s\n", argv[1], 98);

    print_elf_header_info(&header);

    close(fd);
    return (0);
}
