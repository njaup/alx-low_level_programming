#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <elf.h>

/**
 * main - displays the information contained in the ELF header
 * at the start of an ELF file
 * @argc: arguments
 * @argv: arrays of arguments
 * Return: 98
 */
int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}
	if (fd == -1)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return (98);
	}
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		fprintf(stderr, "Error reading ELF header: %s\n", strerror(errno));
		close(fd);
		return (98);
	}
	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return (98);
	}
	printf_magic(fd);
	return (0);
}
/**
 * printf_magic - Read the first 4 bytes from the file
 * into a buffer and compare it with the magic number
 * @fd: file directive
 * Return: 0
 */
void printf_magic(int fd)
{
	int i;
	Elf64_Ehdr header;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	printf("\n");
	printf("Class: %d-bit\n", header.e_ident[EI_CLASS]
			== ELFCLASS64 ? 64 : 32);
	printf("Data: %s\n", header.e_ident[EI_DATA]
	== ELFDATA2LSB ? "2's complement, little endian" :
	"2's complement, big endian");
	printf("Version: %d\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI: %s\n", header.e_ident[EI_OSABI]
			== ELFOSABI_SYSV ? "UNIX System V" : "Others");
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	printf("Type: %s\n", header.e_type == ET_EXEC ?
	"Executable file" : header.e_type
	== ET_DYN ? "Shared object file" : "Others");
	printf("Entry point address: 0x%lx\n", header.e_entry);
	close(fd);
}
