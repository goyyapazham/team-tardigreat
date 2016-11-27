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
 * `char* trim(char *command)`: removes pointer to single command sans leading/trailing whitespace
 * `char** split(char* command, char delim)`: returns an array of commands given a delimiter
 * `void execute(char** word)`: executes a particular command
 * `void cd(char* path)`: changes directory of current process