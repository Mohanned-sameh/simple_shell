#include "main.h"

/**
 * main - Entry point.
 * @ac: Argument count.
 * @av: Argument vector.
 * @env: Environment.
 * Return: 0.
 */
int main(int ac, char **av, char **env)
{
	char *userline = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;
	char **args;
	int i;

	(void)ac;
	(void)av;
	while (1)
	{
		fflush(stdout);
		characters_read = getline(&userline, &bufsize, stdin);
		if (characters_read == -1)
			break;
		userline[mystrcspn(userline, "\n")] = '\0';
		if (mystrcmp(userline, "exit") == 0)
		{
			free(userline);
			exit(0);
		}
		if (mystrcmp(userline, "env") == 0)
		{
			myprintenv(env);
			continue;
		}
		args = mytoken(userline);
		if (args != NULL && args[0] != NULL)
			myexecute(args);

		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
	if (userline != NULL)
		free(userline);

	return (0);
}
