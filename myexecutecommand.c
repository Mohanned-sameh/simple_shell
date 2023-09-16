#include "main.h"
/**
 * executecommand - executes a command using execve
 * @args: command to be executed
 * Return: void
 */
void executecommand(char **args)
{
	char *cmd = NULL, *realcmd = NULL;

	if (args)
	{
		cmd = args[0];
		realcmd = getuserpath(cmd);
		if (execve(realcmd, args, NULL) == -1)
			mywrite("Command not found\n");
	}
}
