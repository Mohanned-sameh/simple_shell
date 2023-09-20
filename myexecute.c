#include "main.h"

/**
 * myexecute - Executes a command.
 * @args: Arguments.
 * @env: Environment.
 * Return: void
 */
void myexecute(char **args, char **env)
{
	char *command = getpath(args[0]);
	pid_t pid = fork();
	int status;

	if (command == NULL)
	{
		perror("Error");
		exit(1);
	}

	if (pid == -1)
	{
		perror("Error");
		free(command);
		exit(1);
	}
	else if (pid == 0)
	{
		execve(command, args, env);
		perror("Error");
		free(command);
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
