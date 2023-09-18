#include "main.h"
/**
 * main - entry point
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *userlines = NULL;
	size_t len = 0;
	ssize_t userlinesread;
	char *tokens[MAX_TOKENS];
	int numoftokens;

	(void)ac;
	(void)av;
	while (1)
	{
		myprint("$ ");
		userlinesread = getline(&userlines, &len, stdin);
		handletext(userlinesread);
		numoftokens = 0;
		tokens[numoftokens] = strtok(userlines, " \n");
		if (strcmp(tokens[0], "env") == 0)
		{
			myprintenv(env);
		}
		while (tokens[numoftokens] != NULL && numoftokens < MAX_TOKENS - 1)
		{
			numoftokens++;
			tokens[numoftokens] = strtok(NULL, " \n");
		}
		tokens[numoftokens] = NULL;
		if (numoftokens > 0)
		{
			executecmd(tokens);
		}
	}

	free(userlines);
	return (0);
}
/**
 * handletext - handles text
 * @text: text
 */
void handletext(ssize_t text)
{
	if (text == -1)
	{
		perror("Error\n");
		exit(1);
	}
}
