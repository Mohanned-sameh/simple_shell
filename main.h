#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int myprint(char *str);
char **mytoken(char *userLine);
void myprintenv(char **env);
void myexecute(char **args, char **env);
char *getpath(char *command);

#endif
