#include <stdio.h>

int is_leap_year(int year){
	if((year % 4 == 0) && (year % 100 != 0)){
		return 1;
	}else if(year % 400 == 0){
		return 1;
	}
	return 0;
}

int main(){
	int n;
	printf("Enter a year number:");
	scanf("%d", &n);
	if(is_leap_year(n)){
		printf("Is a leap year\n");
	}else{
		printf("Not a leap year\n");
	}
}
