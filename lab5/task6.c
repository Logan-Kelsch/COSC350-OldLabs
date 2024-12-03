/* Logan Kelsch, Lab 5-6, Task 6 */

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1

//error output function
void err_sys(char *str){
	printf(str);
	exit(1);
}

//main
int main(int argc, char *argv[]){
	//command line validation
	if(argc!=2)
		err_sys("COMMAND LINE INPUT ERROR");
	//declare input file name
	char *inName = argv[1];
	int inFileDes = open(inName, O_RDONLY);
	//open with success validation
	if(inFileDes == -1)
		err_sys("OPEN IN ERROR");
	//create process ID variable
	pid_t pid;
	//				--success here
	int childDes = open("child.txt",O_RDWR|O_CREAT,0666);
	int parentDes = open("parent.txt",O_RDWR|O_CREAT,0666);
	//create output file descriptor with validation check
	if(childDes == -1 || parentDes == -1)
		err_sys("OPEN OUT ERROR");
	//buffer for reading and writing
	char buffer[BUFFER_SIZE];
	int nbyte = 1;
	//pid fork for child and parent
	pid = fork();
	if(pid==-1)//ERROR CASE
		err_sys("ERROR: PID = -1");
	//while loop will iterate through until the either the input
	//or output file is brought to their own end and cannot continue
	while(nbyte>0){
		printf("inWHILELOOKP\n");
		if(pid==0){
			if((nbyte = read(inFileDes,buffer,1)) < 1)
				printf("CHILD UNABLE TO READ\n");
			if((nbyte = write(childDes,buffer,1)) < 1)
				printf("CHILD UNABLE TO WRITE\n");
		}
		if(pid==1){
			if((nbyte = read(inFileDes,buffer,1)) < 1)
				printf("PARENT UNABLE TO READ\n");
			if((nbyte = write(parentDes,buffer,1)) < 1)
				printf("PARENT UNABLE TO WRITE\n");
		}
		printf("nbyte:%d\n",nbyte);
		if(nbyte==0)
			break;
	}
	printf("far end of switch statement\n");
	exit(0);
	
}
