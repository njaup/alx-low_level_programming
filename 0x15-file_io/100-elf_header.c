#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void display_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

void display_elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		display_error("Error opening file");
    }

    // Read first bytes to check ELF identification
    char ident[4];
    if (read(fd, ident, 4) != 4 || ident[0] != 0x7F || ident[1] != 'E' || ident[2] != 'L' || ident[3] != 'F') {
        display_error("Not an ELF file");
    }

    // Seek to the start of the ELF header
    if (lseek(fd, 0, SEEK_SET) != 0) {
        display_error("Error seeking to ELF header");
    }

    // Read ELF header
    Elf32_Ehdr elf_header; // Use Elf64_Ehdr for 64-bit ELF
    if (read(fd, &elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr)) {
        display_error("Error reading ELF header");
    }

    // Display ELF header information
    printf("Magic: "); // Display magic number according to format
    // Display other required information similarly using printf

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    display_elf_header(argv[1]);

    return 0;
}
