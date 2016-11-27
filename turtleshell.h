// ================== PARSE FXNS ==================
//removes pointer to single command sans leading/trailing whitespace
char* trim(char *command);
//returns an array of commands given a delimeter (e.g., ';', ' ')
char** split(char* command, char delim);

// ================== SHELL FXNS ==================
//executes a particular command
void execute(char** word);
