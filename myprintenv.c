#include "main.h"

/**
 * myprintenv - Prints the environment.
 * @env: Environment.
 */
void myprintenv(char **env)
{
	while (*env != NULL)
	{
		myprint(*env);
		env++;
		myprint("\n");
	}
}
