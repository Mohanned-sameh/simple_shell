#include "main.h"
/**
 * executecmd - executes commands
 * @args: arguments
 */
void executecmd(char **args)
{
	pid_t childid;
	int status;
	char *actualcmd, *cmd = NULL;

	cmd = args[0];
	actualcmd = getpath(cmd);
	if (strcmp(cmd, "exit") == 0)
	{
		myprint("Exiting..\n");
		exit(0);
	}
	else
	{
		childid = fork();
		if (childid == -1)
		{
			perror("Fork failed");
			exit(1);
		}
		if (actualcmd)
		{
			if (childid == 0)
			{
				if (execve(actualcmd, args, NULL) == -1)
				{
					perror("Error");
					exit(1);
				}
			}
			else
			{
				wait(&status);
			}
		}
	}
}
