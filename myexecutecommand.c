#include "main.h"
/**
 * executecommand - executes a command using execve
 * @args: command to be executed
 * Return: void
 */
void executecommand(char **args)
{
	char *cmd = NULL;

	if (args)
	{
		cmd = args[0];

		if (execve(cmd, args, NULL) == -1)
			perror("ERROR COMMAND NOT FOUND!");
	}
}
