#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int myprint(char *str);
size_t token(char *str, char *delim);
char **wordsarray(char *str, char *delim);
void printenv(char **env);
void execute(char **args);

#endif