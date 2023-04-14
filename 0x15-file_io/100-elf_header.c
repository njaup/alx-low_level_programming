#include "main.h"
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>

/**
 * main - displays the information contained in the ELF header
 * at the start of an ELF file
 * @argc: arguments
 * @argv: arrays of arguments
 * Return: If the file is not an ELF file, or on error,
 * exit with status code 98 and display
 * a comprehensive error message to stderr
 */
int main(int argc, char **argv)
{
	FILE *fp;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		printf(stderr, "Usage: %s <ELF file>", argv[0]);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	if (fread(&header, sizeof(header), 1, fp) != 1)
	{
		printf(stderr, "Error reading ELF header");
		printf("\n");
		exit(EXIT_FAILURE);
	}
	printf("ELF header:");
	printf("\n");
	printf(" Magic: ");

	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
printf("\n");
printf(" Class:			%d\n", header.e_ident[EI_CLASS] == ELFCLASS64
printf(" Data:			%s\n", header.e_ident[EI_DATA] == ELFDATA2LSB
printf(" Version:		%d\n", header.e_ident[EI_VERSION]);
printf(" OS/ABI:		%d\n", header.e_ident[EI_OSABI]);
PRINTF(" ABI Version:		%d\n", haeder.e_ident[EI_ABIVERSION]);
printf(" Type:			%d\n", header.e_type);
printf(" Entry point address:	0x%lx\n", header.e_entry);

fclose(fp);
return (0);
}
