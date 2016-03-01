#include <stdio.h>

int main(){
	char c;
	int n = 0;
	printf("Enter a number:");
	
	while((c = getchar()) != '.'){}
	
	while((c = getchar()) != EOF){
		n++;
	}
	
	printf("%d decimal digits\n", n);
}
