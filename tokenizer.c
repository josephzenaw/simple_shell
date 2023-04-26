#include "shell.h"

/**
 * tokenize - tokenizes a stirng
 * @lineptr: what the user inputed
 * Return: a ptr to arr of ptrs
 */

char **tokenize(char *lineptr)
{
	char **user_commands = NULL;
	char *tokening = NULL;
	size_t i = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptr))
		return (NULL);
	user_commands = malloc(sizeof(char *) * (size + 2));
	if (user_commands == NULL)
		return (NULL);

	tokening = strtok(lineptr, " \n\t\r");

	for (i = 0; tokening != NULL; i++)
	{
		user_commands[i] = tokening;
		tokening = strtok(NULL, " \n\t\r");
	}
	user_commands[i] = NULL;
	return (user_commands);
}
