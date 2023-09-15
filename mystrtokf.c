#include "main.h"
/**
 * mystrtokf - same as strtok normally
 * @inp: the string
 * Return: the token
 */
char *mystrtokf(char *inp)
{
	char *str = inp;
	char *delimiter = " ";
	char *token;

	token = strtok(str, delimiter);
	while (token)
	{
		token = strtok(NULL, delimiter);
	}
	return (str);
}
