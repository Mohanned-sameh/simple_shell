#include "main.h"
/**
 * myexecute - Executes a command.
 * @args: Arguments.
 * Return: void
 */
void myexecute(char **args)
{
	char *command = NULL;
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			command = getpath(args[0]);
			if (command == NULL)
			{
				perror("Error");
				exit(1);
			}

			if (execve(command, args, NULL) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
	}
	else
	{
		wait(&status);
	}
	free(command);
}
