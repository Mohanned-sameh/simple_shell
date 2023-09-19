#include "main.h"
/**
 * execute - execute commands
 * @args: arguments
 * Return: void
 */
void execute(char **args)
{
	pid_t pid;
	int status;
	char *command;

	if (args[0] == NULL)
		return;
	pid = fork();
	command = getpath(args[0]);
	if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
