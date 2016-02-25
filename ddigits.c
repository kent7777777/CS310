#include <stdio.h>

int main(){
	int c;
	int n = 0;
	
	while(!(c = getchar()).Equals('.')){}
	
	while((c = getchar()) != EOF){
		n++;
	}
	
	printf("%d decimal digits\n", n);
}
