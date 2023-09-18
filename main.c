#include "main.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 * Return: Always 0 (Success)
 */
int main(int ac, char **av, char **env)
{
	char *userline = NULL, *userlinecopy = NULL, *token = NULL,
		 *delimiter = " \n";
	size_t length = 0;
	ssize_t userlineread;
	int numoftokens = 0, i;

	(void)ac;
	while (1)
	{
		mywrite("$ ");
		userlineread = getline(&userline, &length, stdin);
		userlinecopy = malloc(sizeof(char) * userlineread);
		checktext(userline, env, userlineread);
		strcpy(userlinecopy, userline);
		token = strtok(userline, delimiter);
		while (token != NULL)
		{
			numoftokens++;
			token = strtok(NULL, delimiter);
		}
		numoftokens++;
		av = malloc(sizeof(char *) * numoftokens);
		token = strtok(userlinecopy, delimiter);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delimiter);
		}
		av[i] = NULL;
		executecommand(av);
	}
	free(userlinecopy);
	free(userline);
	return (0);
}
/**
 * checktext - checks if the user input is valid
 * @text: user input
 * @env: environment variables
 * @userlineread: number of bytes read from stdin
 * Return: nothing
 */
void checktext(char *text, char **env, ssize_t userlineread)
{

	if (userlineread == -1)
	{
		perror("Error: Unable to read from stdin\n");
		exit(1);
	}
	if (strcmp(text, "exit\n") == 0)
	{
		mywrite("Goodbye!\n");
		exit(1);
	}
	if (strcmp(text, "env\n") == 0)
	{
		print_environment_variables(env);
	}
}
