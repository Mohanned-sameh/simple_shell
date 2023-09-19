#include "main.h"
/**
 * token - tokenize line
 * @str: string
 * @delim: delimiter
 * Return: number of words
 */
size_t token(char *str, char *delim)
{
	size_t word = 0;

	strtok(str, "\n");
	if (strtok(str, delim) != NULL)
		++word;
	while (strtok(NULL, delim))
		++word;
	return (word);
}
