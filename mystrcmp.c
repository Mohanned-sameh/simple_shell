#include "main.h"
/**
 * mystrcmp - compares two strings
 * @str: first string
 * @str2: second string
 * Return: 0 if they are equal, 1 if not
 */
int mystrcmp(char *str, char *str2)
{
    int i, j;

    i = 0;
    j = 0;
    while (str[i] != '\0' && str2[j] != '\0')
    {
        if (str[i] != str2[j])
        {
            return (1);
        }
        i++;
        j++;
    }
    return (0);
}