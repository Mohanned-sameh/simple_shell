#include "main.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	char *line = NULL, *linecopy = NULL;
	size_t len = 0;
	ssize_t read;
	const char *delimiter = " \n";
	int numoftokens = 0, i;
	char *token;

	(void)ac;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("ERROR\n");
			return (-1);
		}
		linecopy = malloc(sizeof(char) * read);
		if (linecopy == NULL)
		{
			printf("MEMORY ERROR!\n");
			return (-1);
		}
		strcpy(linecopy, line);
		token = strtok(linecopy, delimiter);
		while (token != NULL)
		{
			numoftokens++;
			token = strtok(NULL, delimiter);
		}
		numoftokens++;
		av = malloc(sizeof(char *) * numoftokens);
		token = strtok(linecopy, delimiter);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delimiter);
		}
		av[i] = NULL;
		executecmd(av);
	}
	free(linecopy);
	free(line);
	return (0);
}
/**
 * executecmd - executes the command
 * @av: command to be executed
 * Return: void
 */
void executecmd(char **av)
{
	char *cmd = NULL, *actualcmd = NULL;

	if (av)
	{
		cmd = av[0];
		actualcmd = getloc(cmd);

		if (execve(actualcmd, av, NULL) == -1)
			perror("ERROR!");
	}
}
/**
 * getloc - get user dir location
 * @cmd: cmd to be executed in the dir location
 * Return: dir location
 */
char *getloc(char *cmd)
{
	char *p, *pcp, *ptoken, *fp = NULL;
	int cmdlength, dirlength;
	struct stat buf;

	p = getenv("PATH");
	if (p)
	{
		pcp = strdup(p);
		cmdlength = strlen(cmd);
		ptoken = strtok(pcp, ":");
		while (ptoken != NULL)
		{
			dirlength = strlen(ptoken);
			fp = malloc(dirlength + cmdlength + 2);
			strcpy(fp, ptoken);
			strcat(fp, "/");
			strcat(fp, cmd);
			strcat(fp, "\0");
			if (stat(fp, &buf) == 0)
			{
				free(pcp);
				return (fp);
			}
			else
			{
				free(fp);
				ptoken = strtok(NULL, ":");
			}
		}
		free(pcp);
		if (stat(cmd, &buf) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}