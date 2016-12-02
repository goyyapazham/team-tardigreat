# team-tardigreat
* https://en.wikipedia.org/wiki/Tardigrade
* enrichment: http://www.wikihow.com/Use-a-Fork-and-Knife, https://en.wikipedia.org/wiki/Fork

### by Nalanda Sharadjaya and Stephanie Yoon

## Features:
* Forks and executes commands!
* Exit, cd
* Parses multiple commands on one line, separated by a semicolon
* Simple Redirection (< and >)
* Simple Pipe (only one |)
	
## Attempted:
* Tried to make >>, but couldn't figure out how to parse the string.
* Couldn't fix issue with terminating null with some redirect tests

## Bugs:
* execute doesn't check, if word[0] is "cd", that word[1] is a real directory
* If there is already a file named "file" in the directory, pipe won't work because it creates and then removes a file by that name.
* Does not check for escape sequences
* Putting two ;'s next to each other will break the parser
* Sometimes when you redirect to a file it writes a file with junk at the end indicating the string didn't have a terminating null????

##Files and Function Headers:
### turtleshell.c
* just has main function
### utils.c
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
void greater(char** c, char* file);
//redirects stdin from a file (imitates <)
void less(char** c, char* file);
//redirects stdout from one command to stdin of next (imitates |)
void pipeitup(char** c0, char** c1);

```