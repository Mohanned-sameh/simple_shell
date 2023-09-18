#include "main.h"
/**
 * myprint - prints to stdout
 * @str: string to print
 * Return: void
 */
int myprint(char *str)
{
	return (write(1, str, strlen(str)));
}
