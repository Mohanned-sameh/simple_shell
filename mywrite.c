#include "main.h"
/**
 * mywrite - writes to stdout
 * @str: string to write
 * Return: number of characters written
 */
int mywrite(char *str)
{
	return (write(1, str, strlen(str)));
}
