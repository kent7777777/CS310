#include <stdio.h>

int main(){
	int n;
	printf("Enter a number from 1 to 99:");
	scanf("%d", &n);
	
	printf("%d Quarters\n", (n / 25));
	n = n % 25;
	printf("%d Dimes\n", (n / 10));
	n = n % 10;
	printf("%d Nickles\n", (n / 5));
	n = n % 5;
	printf("%d Pennies\n", n);
}
