#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/file.h>

#define MAXLINE 80
#define MAXARG 20
#define MAXHIS 1000
#define WHITE " \n\t"

int directpoint;
int pipenum;

char* redirection(char* argv[], int len){
	int i;
	int pointer = -1;
	char* direction = ""; 
	for(i = 0; i < len; i++){
		if(!strcmp(argv[i], ">")){
			direction = ">";
			pointer = directpoint = i;
		}else if(!strcmp(argv[i], "<")){
			direction = "<";
			pointer = directpoint = i;
		}else if(!strcmp(argv[i], ">>")){
			direction = ">>";
			pointer = directpoint = i;
		}else if(!strcmp(argv[i], "|")){
			direction = "|";
			pointer = directpoint = i;
			pipenum++;
		}	
	}
	if((pointer > -1) && pipenum < 2){
		for(i = pointer; i < len; i++){
			argv[i] = argv[i+1];
		}
		argv[i] = NULL;
	}
	return direction;
}

void piper(char* argv[]){
	char* argout[MAXARG];
	char* argin[MAXARG];
	int i;
	int j = 0;
	for(i = 0; i < directpoint; i++){
		argout[i] = argv[i];
	}
	argout[i] = NULL;
	for(i = directpoint; argv[i] != NULL; i++){
		argin[j] = argv[i];
		j++;
	}
	argin[j] = NULL;
	printf("Prog1: %s  Prog2: %s\n", argout[0], argin[0]);

	int thepipe[2];
	pipe(thepipe);
	if(fork() == 0){
		close(thepipe[0]);
		dup2(thepipe[1], 1);
		execv(argout[0], argout);
		_exit(1);
	}
	if(fork() == 0){
		close(thepipe[1]);
		dup2(thepipe[0], 0);
		execv(argin[0], argin);
		_exit(1);
	}
}

void multipiper(char* argv[]){
	printf("in multipiper\n");
	int directpointers[pipenum];
	directpointers[0] = 0;
	int directlen = 1;
	int i;
	int j;
	for(i = 0; argv[i] != NULL; i++){
		if(!strcmp(argv[i], "|")){
			directpointers[directlen++] = i;
			for(j = i; argv[j] != NULL; j++){
				argv[j] = argv[j+1];
			}
		}
		directpointers[directlen++] = -1;
	}
	printf("%d\n", directlen);
	char** args[100];
	int pipes[directlen][2];
	for(i = 0; i < directlen; i++){
		pipe(pipes[i]);
		for(j = directpointers[i]; j < directpointers[i+1]; j++){
			printf("looping\n");
			(args[i])[j - directpointers[i]] = argv[j];
		}
	}
	printf("%d\n", directlen);
	for(i = 0; i < directlen; i++){
		printf("looping\n");
		if(fork() == 0){
			if(i != 0){
				dup2(pipes[i-1][0], 0);
			}
			if(i != directlen-1){
				dup2(pipes[i][1], 1);
			}
			execv((args[i])[0], args[i]);
			_exit(1);
		}
	}
}

int tokenize(char* cmd, char* argv[]){
	int i = 0;
	char* tok = strtok(cmd, WHITE);
	argv[i++] = tok;
	while(tok != NULL){
		argv[i++] = tok = strtok(NULL, WHITE);
	}
	
	if(i >= MAXARG){
		return 0;
	}else{
		return i-1;
	}
}

int background(char* argv[], char* direction){
	union wait status;
	int id = fork();
	if(id == 0){
		if(!strcmp(direction, ">")){
			int fd = open(argv[directpoint], O_WRONLY|O_CREAT);
			dup2(fd, 1);
			close(fd);
			argv[directpoint] = NULL;
		}else if(!strcmp(direction, "<")){
			int fd = open(argv[directpoint], O_RDONLY);
			dup2(fd, 0);
			close(fd);
			argv[directpoint] = NULL;
		}else if(!strcmp(direction, ">>")){
			int fd = open(argv[directpoint], O_WRONLY|O_APPEND|O_CREAT);
			dup2(fd, 1);
			close(fd);
			argv[directpoint] = NULL;
		}
		if(!strcmp(direction, "|")){
			if(pipenum == 1){
				piper(argv);
			}else{
				multipiper(argv);
			}
		}else{
		execv(argv[0], argv);
		}
		_exit(1);
	}else if(id < 0){
		fprintf(stderr, "fork failed\n");
		perror("background");
	}
	wait(&status);
	if (status.w_status != 0) {
		printf("Unhappy child\n");
	}
	return id;
}

int main(){
	char cmd[MAXLINE+1];
	char* argv[MAXARG+1];
	char* argh[MAXHIS];
	int hislen = 0;
	int i;
	char* got;
	int tokres;
	int templen;
	while(1){
		directpoint = 0;
		pipenum = 0;
		printf("mysh ready$ ");
		got = fgets(cmd, MAXLINE, stdin);
		if(got == NULL){
			printf("\n");
			exit(0);
		}
		
		if(strlen(cmd) > MAXLINE-1 && strpbrk(cmd, "\n") == NULL){
			fprintf(stderr, "exeeded maxline");
		}else if(((tokres = tokenize(cmd, argv)) == 0)){	

		}else if(!strcmp(argv[0], "cd")){
			chdir(argv[1]);
		}else if(!strcmp(argv[0], "history")){
			for(i = 0; i < hislen; i++){
				printf("%s\n", argh[i]);
			}
		}else{
			if(!strcmp(argv[tokres-1], "&")){
				argv[tokres-1] = NULL;
				if(fork() == 0){
					background(argv, redirection(argv, tokres-1));
				}
			}else{
				background(argv, redirection(argv, tokres-1));
			}
		}
		i = 0;
		templen = hislen;
		while(hislen < (templen + tokres)){
			argh[hislen] = argv[i];
			i++;
			hislen++;
		}
		
	}
}
