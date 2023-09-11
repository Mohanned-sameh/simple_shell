#include "main.h"
/**
 * myprintf - prints a string
 * @argv: argument vector
 * Return: char
 */
char *myprintf(char *argv)
{
	size_t len = strlen(argv);

	write(1, argv, len);
	return (argv);
}
