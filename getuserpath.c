#include "main.h"
/**
 * getuserpath - returns the path the user is at
 * @cmd: command to be executed at user path
 * Return: path of user
 */
char *getuserpath(char *cmd)
{
	char *path = NULL, *copyofpath = NULL, *filepathex = NULL;
	int len = 0, dirlength;
	char *tokenofpath;
	struct stat st;

	path = getenv("PATH");
	if (path)
	{
		copyofpath = strdup(path);
		len = strlen(cmd);
		tokenofpath = strtok(copyofpath, ":");
		while (tokenofpath != NULL)
		{
			dirlength = strlen(tokenofpath);
			filepathex = malloc(sizeof(char) * (dirlength + len + 2));
			strcpy(filepathex, tokenofpath);
			strcat(filepathex, "/");
			strcat(filepathex, cmd);
			strcat(filepathex, "\0");
			if (stat(filepathex, &st) == 0)
			{
				free(copyofpath);
				return (filepathex);
			}
			else
			{
				free(filepathex);
				tokenofpath = strtok(NULL, ":");
			}
		}
		free(copyofpath);
		if (stat(cmd, &st) == 0)
			return (cmd);

		return (NULL);
	}
	return (NULL);
}
