#include "main.h"

/**
 * read_textfile - this will read a text file and print the letters
 * @filename: this is the filename.
 * @letters: is the number of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int z;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	z = open(filename, O_RDONLY);

	if (z == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(z, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(z);

	free(buf);

	return (nwr);
}
