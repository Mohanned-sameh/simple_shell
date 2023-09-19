#include "main.h"
/**
 * printenv - print environment
 * @env: environment
 * Return: void
 */
void printenv(char **env)
{
	for (; *env; env++)
	{
		myprint(*env);
		myprint("\n");
	}
}
