#include "main.h"

/**
 * mystrcat - concatenates two strings
 * @s1: destination string
 * @s2: source string
 * Return: pointer to the resulting string (s1)
 */
char *mystrcat(char *s1, const char *s2)
{
	int i, j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
