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

	myprint("$ ");
	(void)ac;
	while (1)
	{
		read = getline(&line, &len, stdin);
		if (read == -1)
			exit(0);
		strcpy(linecopy, line);
		av = wordsarray(linecopy, " ");
		execute(av, env);
		free(av);
		av = NULL;
		myprint("$ ");
	}
	free(line);
	free(linecopy);
	return (0);
}
