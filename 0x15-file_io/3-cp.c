#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * print_error - prints error messages to stderr
 * @message: the error message to print
 * @arg: argument for the error message (if any)
 * @exit_code: exit code to return
 */
void print_error(const char *message, const char *arg, int exit_code)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(exit_code);
}

/**
 * close_fd - closes a file descriptor and prints an error if it fails
 * @fd: the file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies the contents of one file to another
 * @from_fd: file descriptor of the source file
 * @to_fd: file descriptor of the destination file
 */
void copy_file(int from_fd, int to_fd)
{
	ssize_t n_read, n_written;
	char buffer[BUF_SIZE];

	while ((n_read = read(from_fd, buffer, BUF_SIZE)) > 0)
	{
		n_written = write(to_fd, buffer, n_read);
		if (n_written != n_read)
		{
			print_error("Error: Can't write to %s\n", NULL, 99);
		}
	}

	if (n_read == -1)
	{
		print_error("Error: Can't read from file %s\n", NULL, 98);
	}
}

/**
 * main - copies the contents of one file to another
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 * 
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		print_error("Error: Can't read from file %s\n", argv[1], 98);
	}

	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		close_fd(from_fd);
		print_error("Error: Can't write to %s\n", argv[2], 99);
	}

	copy_file(from_fd, to_fd);

	close_fd(from_fd);
	close_fd(to_fd);

	return (0);
}
