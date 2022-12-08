#ifndef MAIN_H
#define MAIN_H
/*Libraries*/
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
/*Prototypes*/
int main(int ac, char *av[], char *ev[]);
void handle_signal(int signal);
int exec_cmd(char *av[], char *ev[]);
int get_cmd(char *str, size_t size, char *ev[]);

#endif

