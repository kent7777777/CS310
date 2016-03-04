#include <stdio.h>

int **mk_array(int r, int c){
	int **array;
	int i;
	int j;
	int n = 0;
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			array[i][j] = n;
			n++;
		}
	}
}

int main(){
	int **data = mk_array(10, 10);
	
	
	
}
