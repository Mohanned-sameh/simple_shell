#include "main.h"

/**
 * mytoken - Tokenizes a string.
 * @userLine: User input.
 * Return: Tokenized string.
 */
char **mytoken(char *userLine)
{
	char **tokens = malloc(sizeof(char *) * 100);
	char *token;
	int tokencount = 0;

	if (tokens == NULL)
	{
		perror("Error");
		exit(1);
	}

	token = strtok(userLine, " ");
	while (token != NULL)
	{
		tokens[tokencount] = mystrdup(token);
		if (tokens[tokencount] == NULL)
		{
			perror("Error");
			exit(1);
		}
		tokencount++;
		token = strtok(NULL, " ");
	}

	tokens[tokencount] = NULL;
	return (tokens);
}
