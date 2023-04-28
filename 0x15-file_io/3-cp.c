#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_error(int error_code, const char *message,
		const char *file_name, int fd)
{
	dprintf(STDERR_FILENO, message, file_name);
	if (fd != -1)
	{
		close(fd);
	}
	exit(error_code);
}
/**
 * main - copies the content of a file to another file
 * @argc: arguments
 * @argv: an array of arguments
 * Return: if file_to already exists, truncate it
 */
int main(int argc, char *argv[])
{
	int fd_f, fd_t, b_read, b_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	fd_f = open(argv[1], O_RDONLY);
	if (fd_f == -1)
	{
		print_error(98, "Error: cant read from file %s\n", argv[2], fd_f);
	}
	fd_t = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_t == -1)
	{
		print_error(99, "Error: cant write to %s\n", argv[2], fd_f);
	}
	while ((b_read = read(fd_f, buffer, BUFFER_SIZE)) > 0)
	{
		b_written = write(fd_t, buffer, b_read);
		if (b_written != b_read)
		{
			print_error(99, "Error: cant write to %s\n", argv[2], fd_f);
		}
	}
	if (b_read == -1)
	{
		print_error(98, "Error: cant read from file %s\n", argv[1], fd_t);
	}
	if (close(fd_f) == -1)
	{
		print_error(100, "Error: cant close fd %d\n", argv[1], fd_t);
	}
	if (close(fd_t) == -1)
	{
		print_error(100, "Error: cant close fd %d\n", argv[2], fd_f);
	}
	return (0);
}
