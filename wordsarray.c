#include "main.h"
/**
 * wordsarray - tokenize line
 * @str: string
 * @delim: delimiter
 * Return: words
 */
char **wordsarray(char *str, char *delim)
{
	char **av = NULL, prevchar = '\0';
	size_t strsize = strlen(str), i;
	size_t arrsize = token(str, delim);
	int j = 0;

	av = malloc(sizeof(char *) * (arrsize + 1));
	for (i = 0; i < strsize; i++)
	{
		if (str[i] != '\0' && prevchar == '\0')
		{
			av[i] = str + i, j++;
		}
		prevchar = str[i];
		av[j] = NULL;
	}
	return (av);
}
