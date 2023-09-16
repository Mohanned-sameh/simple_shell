#include "main.h"
/**
 * executecommand - executes a command using execve
 * @args: command to be executed
 * Return: void
 */
void executecommand(char **args)
{
	char *cmd = NULL, *realcmd = NULL;
	pid_t childpid;
	int status;

	if (args)
	{
		cmd = args[0];
		realcmd = getuserpath(cmd);

		childpid = fork();
		if (childpid == -1)
			perror("Error in forking\n");
		else if (childpid == 0)
		{
			if (execve(realcmd, args, NULL) == -1)
			{
				mywrite("command not found\n");
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
