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
char* trim(char *command) {//causes seg faults for one letter command
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
void greater(char** c, char* file) {
  int newstdout = dup(STDOUT_FILENO);
  
  //umask(0);
  file = trim(file); //command = trim(command);
  int f = open(file, O_WRONLY|O_CREAT, 0644);
  printf("%s, %s\n", c[0], file);
  //int w = write(f, command, sizeof(char *));
  dup2(f,STDOUT_FILENO); 
  //int c = close(f);
  //dup2(1, newstdout);
  
  execute(c);
  dup2(newstdout, STDOUT_FILENO);
  close(f);
}
//redirects stdin from a file (imitates <)
void less(char** c, char* file) {
  int newstdin = dup(STDIN_FILENO);
  int f = open(file, O_RDONLY, 0644);
  dup2(f, STDIN_FILENO);
  execute(c);
  dup2(newstdin, STDIN_FILENO);
  close(f);
}


//redirects stdout from one command to stdin of next (imitates |)
//void pipeitup(char** word);
// ================== REDIR FXNS ==================


// ================== SHELL FXNS ==================
//executes a particular command
void execute(char** word){
  printf("%s\n", word[0]);
  printf("%s\n", word[1]);
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
      if (strchr(word[i], '>') != NULL) {
        c = split(word[i], '>');
	//c[0] = command before >
	//c[1] = command after >
	greater(split(c[0], ' '), c[1]);
	//printf("%s\n", c[0]);
	//printf("%s\n", c[1]);
	//greater(c, c[1]);
      }
      else if (strchr(word[i], '<') != NULL) {
	c=split(word[i], '<');
	less(split(c[0], ' '), c[1]);
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
