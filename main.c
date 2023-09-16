#include "main.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	char *userline = NULL, *userlinecopy = NULL, *token = NULL;
	size_t length = 0;
	ssize_t userlineread;
	const char *delimiter = " ";
	int numoftokens = 0, i;

	(void)ac;
	while (1)
	{
		mywrite("$ ");
		userlineread = getline(&userline, &length, stdin);
		if (userlineread == -1)
		{
			perror("Exiting bye!\n");
			exit(1);
		}
		if (strcmp(userline, "exit\n") == 0)
		{
			mywrite("Goodbye!\n");
			exit(0);
		}
		userlinecopy = malloc(sizeof(char) * userlineread);
		if (userlinecopy == NULL)
		{
			perror("Error: Memory allocation failed!\n");
			exit(1);
		}
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
