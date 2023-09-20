#include "main.h"
/**
 * getpath - gets the path of the executable
 * @command: command to execute
 * Return: path of the executable (or NULL on error)
 */
char *getpath(char *command)
{
	char *path = getenv("PATH");
	char *token, *buff = NULL;
	size_t buff_size;

	if (mystrcmp(command, "/bin/") == 0)
		return (mystrdup(command));
	if (path == NULL || !*path)
		return (NULL);
	while ((token = strtok(path, ":")))
	{
		path = NULL;
		buff_size = mystrlen(token) + mystrlen(command) + 2;
		buff = (char *)malloc(buff_size);
		if (!buff || checkbuf(buff))
			return (NULL);
		mystrcpy(buff, token);
		mystrcat(buff, "/");
		mystrcat(buff, command);
		if (access(buff, F_OK) == 0)
			return (buff);
		free(buff);
	}
	return (NULL);
}

/**
 * checkbuf - checks if the buffer is full
 * @buff: buffer to check
 * Return: 1 if allocation failed, 0 otherwise
 */
int checkbuf(char *buff)
{
	if (buff == NULL)
	{
		perror("malloc");
		return (1);
	}
	return (0);
}
