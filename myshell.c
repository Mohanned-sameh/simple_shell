#include "main.h"
/**
 * myshell - shell to execute commands
 * Return: void
 */
void myshell(void)
{
	char buff[BUFFER_SIZE];
	char *inp = NULL;

	while (1)
	{
		myprintf("myshell$ ");
		inp = mygetlinef();
		strcpy(buff, inp);
		mystrtokf(inp);
		myfork(inp);
		free(inp);
	}
}
