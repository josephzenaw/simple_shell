#include "shell.h"

/**
 * _getline_command -  GEts inputs
 * Return: The input.
 */

char *_getline_command(void) {
	char *lineproptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineproptr, &charter_user, stdin) == -1) {
		free(lineproptr);
		return (NULL);
	}

	return (lineproptr);
}
