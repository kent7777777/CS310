#include <stdio.h>

int main(){
	char* buf = malloc(1024);
	read(0, buf, 1024);
	printf("%s\n", buf);
}
