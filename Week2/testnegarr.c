#include <stdio.h>

int main(){
	int a[] = {1, 2, 3, 4};
	int *p;
	p = 1;
	printf("%d  %d", a[-1], *(p - 1));
	
}
