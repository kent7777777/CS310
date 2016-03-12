#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int status;
	int p1[2];
	int p2[2];
	pipe(p1);
	pipe(p2);
	int pid;
	pid = fork();
	if(pid == 0){
		
