#include "main.h"
/**
 * printenv - print environment
 * @env: environment
 * Return: void
 */
void printenv(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		myprint(env[i]);
		i++;
		myprint("\n");
	}
}
