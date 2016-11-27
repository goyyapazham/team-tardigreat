# team-tardigreat
* https://en.wikipedia.org/wiki/Tardigrade
* enrichment: http://www.wikihow.com/Use-a-Fork-and-Knife, https://en.wikipedia.org/wiki/Fork

### by Nalanda Sharadjaya and Stephanie Yoon

## Features:
* Forks and executes commands!
* Exit, cd
* Parses multiple commands on one line, separated by a semicolon
	
## Attempted:

## Bugs:
* Files and Function Headers:
* turtleshell.c

// ================== PARSE FXNS ==================

//removes pointer to single command sans leading/trailing whitespace

char* trim(char *command);

//returns an array of commands given a delimeter (e.g., ';', ' ')

char** split(char* command, char delim);

// ================== SHELL FXNS ==================

//executes a particular command

void execute(char** word);

//helper function for changing directory

void cd(char* path);
