#include "main.h"
/**
 * mystrcpy - copies the string pointed to by src
 * @src: source
 * @dest: destination
 * Return: string
 */
char *mystrcpy(char *dest, char *src)
{
	int len = 0;
	while (*(src + len) != '\0')
	{
		*(dest + len) = *(src + len);
		len++;
	}
	*(dest + len) = '\0';
	return (dest);
}
