#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_elf_header - prints the ELF header information
 * @e_header: pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *e_header)
{
	printf("ELF Header:\n");
	printf("  Magic:   %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x\n",
		e_header->e_ident[0], e_header->e_ident[1],
		e_header->e_ident[2], e_header->e_ident[3],
		e_header->e_ident[4], e_header->e_ident[5],
		e_header->e_ident[6], e_header->e_ident[7]);
	printf("  Class:                             %d\n", e_header->e_ident[4]);
	printf("  Data:                              %d\n", e_header->e_ident[5]);
	printf("  Version:                           %d\n", e_header->e_ident[6]);
	printf("  OS/ABI:                            %d\n", e_header->e_ident[7]);
	printf("  ABI Version:                       %d\n", e_header->e_ident[8]);
	printf("  Type:                              %d\n", e_header->e_type);
	printf("  Entry point address:               0x%lx\n", e_header->e_entry);
}

/**
 * main - entry point of the program to read and print ELF header
 * @argc: number of arguments
 * @argv: arguments array
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr e_header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(1);
	}

	if (read(fd, &e_header, sizeof(e_header)) != sizeof(e_header))
	{
		dprintf(STDERR_FILENO, "Error: Failed to read ELF header\n");
		close(fd);
		exit(1);
	}

	if (e_header.e_ident[0] != 0x7f || e_header.e_ident[1] != 'E' ||
		e_header.e_ident[2] != 'L' || e_header.e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		exit(1);
	}

	print_elf_header(&e_header);

	close(fd);
	return (0);
}
