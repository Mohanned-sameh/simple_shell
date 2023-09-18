#ifndef _MAIN_H_
#define _MAIN_H_
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_TOKENS 100
int myprint(char *str);
void handletext(ssize_t text);
void executecmd(char **args);
char *getpath(char *cmd);
void myprintenv(char **env);

#endif