#include "main.h"
/**
 * execute - execute commands
 * @args: arguments
 * @env: environment
 * Return: void
 */
void execute(char **args, char **env)
{
	pid_t pid;
	int status, result;
	char *command;

	if (args[0] == NULL)
		return;
	if (strcmp(args[0], "exit") == 0)
		exit(0);
	pid = fork();
	command = getpath(args[0]);
	if (pid == 0)
	{
		if (strcmp(args[0], "env") == 0)
			printenv(env);
		else
		{
			result = execve(command, args, NULL);
			if (result == -1)
			{
				perror("Error");
				exit(1);
			}
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
