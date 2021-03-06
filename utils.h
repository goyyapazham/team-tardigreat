#ifndef UTILS_H
#define UTILS_H

// ================== PARSE FXNS ==================
//removes pointer to single command sans leading/trailing whitespace
char* trim(char *command);
//returns an array of commands given a delimeter (e.g., ';', ' ')
char** split(char* command, char delim);

// ================== SHELL FXNS ==================
//executes a particular command
void execute(char** word);

// ================== REDIR FXNS ==================
//redirects stdout to a file (imitates >)
void greater(char** c, char* file);
//redirects stdin from a file (imitates <)
void less(char** c, char* file);
//redirects stdout from one command to stdin of next (imitates |)
void pipeitup(char** c0, char** c1);

#endif
