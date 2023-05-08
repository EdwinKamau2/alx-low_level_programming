#include "main.h"

/**
 * append_text_to_file - this appends text at the end of a file
 * @filename: is the filename.
 * @text_content: is the NULL terminated string to add at the end of the file.
 *
 * Return: will return 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f_d;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	f_d = open(filename, O_WRONLY | O_APPEND);

	if (f_d == -1)
		return (-1);

	if (text_content)
	{
		for (nletters = 0; text_content[nletters]; nletters++)
			;

		rwr = write(f_d, text_content, nletters);

		if (rwr == -1)
			return (-1);
	}

	close(f_d);

	return (1);
}
