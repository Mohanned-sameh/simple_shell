#include "main.h"
/**
 * wordsarray - tokenize line
 * @str: string
 * @delim: delimiter
 * Return: words
 */
char **wordsarray(char *str, char *delim)
{
	char **av = NULL, prevcharacter = '\0';
	size_t s_size = strlen(str);
	size_t size = token(str, delim);
	size_t i;
	int k = 0;

	av = malloc(sizeof(char *) * (size + 1));

	for (i = 0; i <= s_size; i++)
	{
		if (str[i] != '\0' && prevcharacter == '\0')
		{
			av[k] = &str[i];
			k++;
		}
		prevcharacter = str[i];
	}
	av[k] = NULL;
	return (av);
}
