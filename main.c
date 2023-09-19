#include "main.h"
/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * @env: environment
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL, *linecopy = malloc(sizeof(char) * 1024);
	ssize_t read = 0;
	size_t len = 0;
	int i;

	myprint("$ ");
	(void)ac;
	while (1)
	{
		read = getline(&line, &len, stdin);
		if (read == -1)
			exit(0);
		strcpy(linecopy, line);
		av = wordsarray(linecopy, " ");
		for (i = 0; av[i] != NULL; i++)
		{
			if (strcmp(av[i], "exit") == 0)
				exit(0);
			else if (strcmp(av[i], "env") == 0)
				printenv(env);
		}
		execute(av);
		free(av);
		av = NULL;
		myprint("$ ");
	}
	free(line);
	free(linecopy);
	return (0);
}
