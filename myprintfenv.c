#include "main.h"
/**
 * myprintenv - prints environment
 * Return: 0
 */
void myprintenv(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
	{
		myprint(env[i]);
		myprint("\n");
	}
}
