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
void myexecute(char **args);
size_t mystrcspn(char *s, char *reject);
char *getpath(char *command);
char *mystrcat(char *s1, const char *s2);
char *mystrcpy(char *dest, char *src);
int mystrcmp(char *s1, char *s2);
int checkbuf(char *buff);

#endif
