# team-tardigreat
* https://en.wikipedia.org/wiki/Tardigrade
* enrichment: http://www.wikihow.com/Use-a-Fork-and-Knife, https://en.wikipedia.org/wiki/Fork

### by Nalanda Sharadjaya and Stephanie Yoon

## Features:
* Forks and executes commands!
* Exit, cd
* Parses multiple commands on one line, separated by a semicolon
	
## Attempted:
* Redirect (>), but got caught up in file I/O

## Bugs:
* For some reason, the character p seems to trigger a seg fault??

##Files and Function Headers:
### turtleshell.c
```
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
void greater(char* command, char* file);
//redirects stdin from a file (imitates <)
void less(char** word);
//redirects stdout from one command to stdin of next (imitates |)
void pipe(char** word);
```