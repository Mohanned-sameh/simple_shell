#include "main.h"
/**
 * mygetlinef - gets a line from prompt
 * Return: line
 */
char *mygetlinef(void)
{
	char *buff = NULL;
	size_t len = 0;

	getline(&buff, &len, stdin);
	return (buff);
}
