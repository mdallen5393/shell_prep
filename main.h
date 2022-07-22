#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/* Function Prototypes */
/* --- strops.c --- */
char *strcpycat(char *str1, char *str2);
int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Global Variables */
extern char **environ;

#endif
