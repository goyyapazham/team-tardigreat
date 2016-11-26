#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "parse.h"
/*
void parse(char* command, char** word) {
  *strchr(command, '\n') = 0;
  int i = 0;
  char *x = command;
  while(word[i] = strsep(&x, " ")) i++;
}
*/
void split(char *commandz, char delim, char** word) {
  *strchr(command, '\n') = 0;
  int i = 0;
  char *x = command;
  while(word[i] = strsep(&x, delim)) i++;
}
