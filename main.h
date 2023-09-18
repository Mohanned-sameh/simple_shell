#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int mywrite(char *str);
void executecommand(char **args);
char *getuserpath(char *cmd);
void print_environment_variables(char **environ);
void checktext(char *text, char **env, ssize_t userlineread);

#endif
