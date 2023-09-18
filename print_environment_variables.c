#include "main.h"
/**
 * print_environment_variables - prints the environment variables
 * @environ: environment variables
 */
void print_environment_variables(char **environ)
{
	int i;

	if (environ == NULL)
		return;
	for (i = 0; environ[i] != NULL; i++)
	{
		mywrite(environ[i]);
		mywrite("\n");
	}
}
