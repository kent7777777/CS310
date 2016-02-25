#include <stdio.h>

int main(){
	int n;
	printf("Find the square root of:");
	scanf("%d", &n);
	int i = 0;
	while((i * i) <= n){
		i++;
	}
	printf("%d\n", i - 1);
}
