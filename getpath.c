#include "main.h"

/**
 * getpath - gets the path of the executable
 * @command: command to execute
 * Return: path of the executable (or NULL on error)
 */
char *getpath(char *command)
{
	char *path = getenv("PATH");
	char *copyofpath, *token, *buff;

	if (strncmp(command, "/bin/", 5) == 0)
		return strdup(command);
	if (path == NULL)
		return (NULL);
	copyofpath = strdup(path);
	if (copyofpath == NULL)
	{
		perror("strdup");
		exit(1);
	}
	buff = malloc(strlen(copyofpath) + strlen(command) + 2);
	if (checkbuf(buff))
	{
		free(copyofpath);
		return (NULL);
	}
	token = strtok(copyofpath, ":");
	while (token != NULL)
	{
		strcpy(buff, token);
		strcat(buff, "/");
		strcat(buff, command);
		if (access(buff, F_OK) == 0)
		{
			free(copyofpath);
			return (buff);
		}
		free(buff);
		buff = malloc(strlen(copyofpath) + strlen(command) + 2);
		if (checkbuf(buff))
		{
			free(copyofpath);
			return (NULL);
		}
		token = strtok(NULL, ":");
	}
	free(copyofpath);
	free(buff);
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
		return 1;
	}
	return 0;
}
