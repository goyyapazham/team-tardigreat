#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "turtleshell.h"

void split(char *command, char delim, char** word) {
  *strchr(command, '\n') = 0;
  int i = 0;
  char *x = command;
  while((word[i] = strsep(&x, &delim))) i++;
}

void execute(char** word){
  int f = fork();
  if (f == -1) {
    printf("nah\n");
    exit(1);
  }
  else if(f == 0) {
    if (execvp(word[0], word) < 0) {
      printf("nah\n");
      exit(1);
    }
  }
  else {
    int cstat;
    waitpid(f, &cstat,0);
  }
}

void cd(char* path) {
  //printf("cd %s\n", path);
  chdir(path);
}

int main() {
  char command[100];
  int i;
  char* word[50];
  while(1) {
    printf("tertle >>> ");
    fgets(command, sizeof(command), stdin);
    split(command, ' ', word);
    if (strcmp(word[0], "exit") == 0)
      exit(0);
    if (strcmp(word[0], "cd") == 0)
      cd(word[1]);
    else
      execute(word);
  }
  return 0;
}
