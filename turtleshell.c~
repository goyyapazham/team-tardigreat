#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
  printf("what would you like to do? ");
  char command[100];
  fgets(command, sizeof(command), stdin);
  *strchr(command, '\n') = 0;
  printf("%s", command);
  int i = 0;
  char* word[50];
  char *x = command;
  printf("%s", x);
  while(word[i] = strsep(&x, " ")){
    i++;
  }
  i = 0;
  execvp(word[0], word); 
  return 0;
}
 
