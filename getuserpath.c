#include "main.h"
/**
 * getuserpath - returns the path the user is at
 * @cmd: command to be executed at user path
 * Return: path of user
 */
char *getuserpath(char *cmd)
{
	char *userpath, *userpathcopy, *tokenofpath, *pathoffile;
	int cmdlength, dirlength;
	struct stat st;

	userpath = getenv("PATH");
	if (userpath)
	{
		userpathcopy = strdup(userpath);
		cmdlength = strlen(cmd);
		tokenofpath = strtok(userpathcopy, ":");
		while (tokenofpath != NULL)
		{
			dirlength = strlen(tokenofpath);
			pathoffile = malloc(sizeof(char) * (dirlength + cmdlength + 2));
			strcpy(pathoffile, tokenofpath);
			strcat(pathoffile, "/");
			strcat(pathoffile, cmd);
			strcat(pathoffile, "\0");
			if (stat(pathoffile, &st) == 0)
			{
				free(userpathcopy);
				return (pathoffile);
			}
			else
			{
				free(pathoffile);
				tokenofpath = strtok(NULL, ":");
			}
		}
		free(userpathcopy);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}
