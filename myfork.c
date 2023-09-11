#include "main.h"
/**
 * myfork - create a child process
 * @buff: command to execute
 * Return: void
 */
void myfork(char *buff)
{
	pid_t id;
	int stat;

	buff[strcspn(buff, "\n")] = '\0';
	if (strlen(buff) == 0 || strspn(buff, " \t\n") == strlen(buff))
	{
		myprintf("nothing was entered!\n");
		exit(EXIT_SUCCESS);
	}
	if (strcmp(buff, "exit") == 0)
	{
		myprintf("Bye!\n");
		exit(EXIT_SUCCESS);
	}
	id = fork();
	if (id < 0)
	{
		fprintf(stderr, "Fork Failed");
	}
	else if (id == 0)
	{
		execlp(buff, buff, NULL);
		fprintf(stderr, "Command %s not found\n", buff);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(id, &stat, 0);
	}
}
