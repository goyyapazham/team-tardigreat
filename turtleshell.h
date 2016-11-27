//removes leading/trailing whitespace
char* trim(char *command);
//parses words and idk does stuff
char** split(char* command, char delim);
//executes command in char** word
void execute(char** word);
//change dir
void cd(char* path);
