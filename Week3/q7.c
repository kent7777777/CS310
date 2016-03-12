#include <unistd.h>
#include <stdio.h>

int main(){
	int pipeAB[2]
	int pipeBC[2];
	int pipeCA[2];
	pipe(pipeAB);
	pipe(pipeBC);
	pipe(pipeCA);
	
	int childB = fork();
	if(childb == 0){
		close(pipeCA[0]);
		close(pipeCA[1]);
		close(pipeAB[1]);
		close(pipeBC[0]);
		int buf;
		int r = 0;
		while(r){
			r = read(pipeAB[0], &buf, 1);
			write(pipeBC[1], &buf, 1);
		}
		close(pipeAB[0]);
		close(pipeBC[1]);
	}
}
