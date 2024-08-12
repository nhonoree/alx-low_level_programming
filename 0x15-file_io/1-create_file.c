#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - creates a file and writes text into it
 * @filename: the name of the file to create
 * @text_content: the content to write into the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t text_length;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (text_length = 0; text_content[text_length] != '\0'; text_length++)
			;

		if (write(fd, text_content, text_length) != text_length)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
