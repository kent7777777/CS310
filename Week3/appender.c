#include <stdio.h>

int main(int argc, char* argv[]){
	FILE* in = fopen(argv[2], "a+");
	FILE* out = fopen(argv[1], "r");
	char c;
	while((c = fgetc(out)) != EOF){
		fputc(c, in);
	}
	fclose(in);
	fclose(out);
}
