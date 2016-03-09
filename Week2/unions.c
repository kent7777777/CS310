#include <stdio.h>

typedef union{
	char initial;
	char* name;
} Name;

int make_private(Name* n){
	n->initial = n->name[0];
}
int main(){
	char *s = "Kevin";
	Name n1;
	n1.name = s;
	make_private(&n1);
	printf("%c\n", n1.initial);
}
