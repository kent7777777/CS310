#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double sum(char *FMT, ...){
	double sum = 0;
	va_list ap;
	va_start(ap, fmt);
	for(int i = 0; fmt[i] != '\0'; i++){
		switch(fmt[i]{
			case 'i':
				sum += va_arg(ap, int);
				break;
			case 'f':
				sum += va_arg(ap, float);
				break;
			case 'd':
				sum += va_arg(ap, double);
				break;
		}
		va_end(ap);
		return sum;
		}
	}

int main(int argc, int[] argv){
	
}
