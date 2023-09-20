#include "main.h"

/**
 * myprint - Prints to stdout.
 * @str: String to print.
 * Return: 0.
 */
int myprint(char *str)
{
	return (write(1, str, mystrlen(str)));
}
