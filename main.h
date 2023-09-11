#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256
void myshell(void);
void myfork(char *buff);
char *mygetlinef(void);
char *mystrtokf(char *inp);
char *myprintf(char *argv);

#endif
