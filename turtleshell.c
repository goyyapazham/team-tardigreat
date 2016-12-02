#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

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
      char * n = word[i];
      printf("%s\n", word[i]);
      char * w;
      /*if ((n = strstr(word[i], ">>")) != NULL) {
	n+=2;
	printf("%s\n", n);
	printf("%s\n", word[i]);
	printf("%d\n", (int)(strlen(word[i]) - strlen(n) - 2));
	strncpy(w, word[i], (int)(strlen(word[i]) - strlen(n) - 2));
	printf("%s\n", word[i]);
	//printf("%s\n", w);
	
	}*/
       if (strchr(word[i], '>') != NULL) {
	  c = split(word[i], '>');
	  greater(split(c[0], ' '), c[1]);
      }
      else if (strchr(word[i], '<') != NULL) {
	c=split(word[i], '<');
	less(split(c[0], ' '), c[1]);
      }
      else if (strchr(word[i], '|') != NULL) {
	c=split(word[i], '|');
	pipeitup(split(c[0], ' '), split(c[1], ' '));
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
