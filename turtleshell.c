#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void parse(char* command, char** word) {
  *strchr(command, '\n') = 0;
  int i = 0;
  char *x = command;
  while(word[i] = strsep(&x, " ")) i++;
}

void execute(char** word){
  int f = fork();
  if(f > 0)
    execvp(word[0], word);
}

int main() {
  char command[100];
  int i;
  char* word[50];
  while(1) {
    printf("tertle >>> ");
    fgets(command, sizeof(command), stdin);
    parse(command, word);
    execute(word);
  }
  return 0;
}
