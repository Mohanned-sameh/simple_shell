#include "main.h"
/**
 * mystrlen - returns the length of a string
 * @s: string
 * Return: length
 */
int mystrlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
