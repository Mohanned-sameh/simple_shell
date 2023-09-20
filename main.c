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
	char userline[1024];
	char **args;
	int i;

	(void)ac;
	(void)av;
	while (1)
	{
		fflush(stdout);
		if (fgets(userline, sizeof(userline), stdin) == NULL)
			break;
		userline[strcspn(userline, "\n")] = '\0';
		if (strcmp(userline, "exit") == 0)
			exit(0);
		if (strcmp(userline, "env") == 0)
		{
			myprintenv(env);
			continue;
		}
		args = mytoken(userline);
		if (args != NULL && args[0] != NULL)
			myexecute(args);
		freeargs(args);
	}
	return (0);
}
/**
 * freeargs - free args.
 * @args: args.
 * Return: void
 */
void freeargs(char **args)
{
	for (int i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}