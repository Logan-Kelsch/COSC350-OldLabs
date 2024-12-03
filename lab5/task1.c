/* Logan Kelsch , Lab 5-6, Task 1 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//environment externam variable
extern char **environ;

//my get environment function gathers and prints environment data
void mygetenv(char *str){
	printf("Entered:%s\n",str);
	char **p = environ;
	bool match = true;
	int offset;
	while(*p!=NULL){
		offset=0;
		char *ptr = *p;
		printf("%s\n",ptr);
		while(str[offset]!='\0'){
			//printf("checking..%d - %s,%s\n",offset,str[offset],ptr[offset]);
			if(str[offset]!=ptr[offset]){
				match = false;
				break;
			}
			offset+=1;
		}
		if(match==true){
			printf("\n\nMATCH MATCH\n\n\n");
			break;
		}
		*p++;
	}
}
//main function to call mygetnev function
int main(int argc, char *argv[]){
	//command line validation
	if(argc!=2){
		perror("Command Line error");
		exit(1);
	}
	mygetenv(argv[1]);
	return 0;
}
