#include "main.h"
/**
 * getpath - gets path
 * @cmd: command
 * Return: path
 */
char *getpath(char *cmd)
{
	char *path, *pcopy, *ptoken, *filep;
	int cmdlen, dirlen;
	struct stat st;

	path = getenv("PATH");

	if (path)
	{
		pcopy = strdup(path);
		cmdlen = strlen(cmd);
		ptoken = strtok(pcopy, ":");
		while (ptoken != NULL)
		{
			dirlen = strlen(ptoken);
			filep = malloc(sizeof(char) * (dirlen + cmdlen + 2));
			strcpy(filep, ptoken);
			strcat(filep, "/");
			strcat(filep, cmd);
			if (stat(filep, &st) == 0)
			{
				free(pcopy);
				return (filep);
			}
			else
			{
				free(filep);
				ptoken = strtok(NULL, ":");
			}
		}
		free(pcopy);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}
