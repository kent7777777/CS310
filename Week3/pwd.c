#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int pwd(){
	char* buf = getcwd(NULL, 0);
	printf("%s\n", buf);
}

int main(){
	pwd();
}
