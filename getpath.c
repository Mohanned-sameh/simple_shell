#include "main.h"
/**
 * getpath - gets the path of the executable
 * @cmd: command to execute
 * Return: path of the executable
 */
char *getpath(char *cmd)
{
    char *path, *copyofpath, *pathoffile, *tokenofpath;
    int cmdlen, dirlen;
    struct stat st;

    path = getenv("PATH");

    if (path)
    {
        copyofpath = strdup(path);
        cmdlen = strlen(cmd);
        tokenofpath = strtok(copyofpath, ":");
        while (tokenofpath)
        {
            dirlen = strlen(tokenofpath);
            pathoffile = malloc(sizeof(char) * (dirlen + cmdlen + 2));
            strcpy(pathoffile, tokenofpath);
            strcat(pathoffile, "/");
            strcat(pathoffile, cmd);
            if (stat(pathoffile, &st) == 0)
            {
                free(copyofpath);
                return (pathoffile);
            }
            else
            {
                free(pathoffile);
                tokenofpath = strtok(NULL, ":");
            }
        }
        free(copyofpath);
        if (stat(cmd, &st) == 0)
            return (cmd);
        return (NULL);
    }
    return (NULL);
}