#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "turtleshell.h"

// ================== PARSE FXNS ==================
//removes pointer to single command sans leading/trailing whitespace
char* trim(char *command) {
  char *x = command;
  int len = strlen(x);
  int start=0; int end=len-1;
  while( start < len && strncmp(&x[start], " ", 1) == 0 ) {
    start++;
  }
  while( end > 0 && strncmp(&x[end], " ", 1) == 0 ) {
    end--;
  }
  char *ret = (char *)malloc(end-start-1);
  for(int i=0; i<end-start+1; i++)
    strncpy(&ret[i], &x[i+start], 1);
  return ret;
}
//returns an array of commands given a delimeter (e.g., ';', ' ')
char** split(char *command, char delim) {
  char** word = (char**)malloc(50);
  int i = 0;
  char *x = trim(command);
  while((word[i] = strsep(&x, &delim))) i++;
  return word;
}
// ================== PARSE FXNS ==================


// ================== REDIR FXNS ==================
//redirects stdout to a file (imitates >)
void greater(char* command, char* file) {
  umask(0);
  file = trim(file); command = trim(command);
  int f = open(file, O_WRONLY|O_CREAT, 0644);
  int w = write(f, command, sizeof(char *));
  int c = close(f);
}
//redirects stdin from a file (imitates <)
//void less(char** word);
//redirects stdout from one command to stdin of next (imitates |)
//void pipeitup(char** word);
// ================== REDIR FXNS ==================


// ================== SHELL FXNS ==================
//executes a particular command
void execute(char** word){
  if (strcmp(word[0], "exit") == 0)
    exit(0);
  else if (strcmp(word[0], "cd") == 0)
    chdir(word[1]); //error handle this!
  else {
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
}
// ================== SHELL FXNS ==================


// ================== MAIN   FXN ==================
int main() {
  char command[100];
  int i;
  char** word;
  char** c;
  while(1) {
    printf("tertle >>> ");
    fgets(command, sizeof(command), stdin);
    *strchr(command, '\n') = 0;
    word = (char**)malloc(50);
    word = split(command, ';');
    for (i = 0; word[i] != NULL; i++) {
      c = (char **)malloc(50);
      char** d = split(word[i], '>');
      if( strcmp(word[i], *d) != 0 ) {
	greater(d[0], d[1]);
      }
      else {
	c = split(word[i], ' ');
	execute(c);
      }
    }
  }
  return 0;
}
// ================== MAIN   FXN ==================
