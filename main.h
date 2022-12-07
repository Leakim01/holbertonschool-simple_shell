#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int ac, char *av[], char *ev[]);
void handle_signal(int signal);
int exec_cmd (char *av[], char *ev[]);
char **get_cmd (char *str);

#endif

