#include "main.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	char *userline = NULL, *newuserline = NULL;
	size_t len = 0;
	ssize_t userlinesread;
	const char *delim = " \n";
	int numoftokens = 0, i;
	char *token;

	(void)ac;
	while (1)
	{
		mywrite("$ ");
		userlinesread = getline(&userline, &len, stdin);
		if (userlinesread == -1)
		{
			perror("Error: exiting shell now\n");
			exit(EXIT_SUCCESS);
		}
		newuserline = malloc(sizeof(char) * userlinesread);
		if (newuserline == NULL)
		{
			perror("Error: Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(newuserline, userline);
		token = strtok(newuserline, delim);
		while (token != NULL)
		{
			numoftokens++;
			token = strtok(NULL, delim);
		}
		numoftokens++;
		av = malloc(sizeof(char *) * numoftokens);
		token = strtok(newuserline, delim);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;
		executecommand(av);
	}
	free(newuserline);
	free(userline);

	return (0);
}
