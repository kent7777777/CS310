#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

int ls(char* dir) {
	DIR* dp = opendir(dir);
	struct dirent* entry = readdir(dp);
	while(entry != NULL){
		printf("%s\n", entry->d_name);
		entry = readdir(dp);
	}
	closedir(dp);
}

int searchdir(char* file, char* dir){
	int len = strlen(file);
	DIR* dp = opendir(dir);
	struct dirent* entry;
	
	for(entry = readdir(dp); entry != NULL; entry = readdir(dp)){
		if(!strcmp(entry->d_name, file)){
			return 1;
		}
	}
	closedir(dp);
	return 0;
}

int main(){
	ls("..");
}
