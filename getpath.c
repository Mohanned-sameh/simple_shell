#include "main.h"
/**
 * getpath - gets the path of the executable
 * @command: command to execute
 * Return: path of the executable
 */
char *getpath(char *command)
{
	char *path = getenv("PATH");
	char *copyofpath, *token, *buff;

	if (path == NULL)
		return (NULL);
	copyofpath = strdup(path);
	if (copyofpath == NULL)
	{
		perror("strdup");
		exit(1);
	}
	buff = malloc(strlen(copyofpath) + strlen(command) + 2);
	if (buff == NULL)
	{
		perror("malloc");
		exit(1);
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
			return (strdup(buff));
		}
		token = strtok(NULL, ":");
	}
	free(copyofpath);
	return (NULL);
}
