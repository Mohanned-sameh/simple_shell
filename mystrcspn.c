#include "main.h"
/**
 * mystrcspn - gets the length of a prefix substring
 * @s: string
 * @reject: substring
 * Return: length of substring
 */
size_t mystrcspn(char *s, char *reject)
{
	size_t count = 0, i;
	int found = 0;

	while (s[count] != '\0')
	{
		for (i = 0; reject[i] != '\0'; i++)
		{
			if (s[count] == reject[i])
			{
				found = 1;
				break;
			}
		}
		if (found)
			break;
		count++;
	}
	return (count);
}
