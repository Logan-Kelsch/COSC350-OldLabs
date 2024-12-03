/* Logan Kelsch - COSC 350 -- Lab 4, Task 1 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1

void err_sys(char *str){
	printf ("%s",str);
	exit(1);
}

int main(int argc, char *argv[])
{
	//declare variables
	int offset = 0;
	char buffer[BUFFER_SIZE];
	int nbyte;
	//ensure correct number of inputs
	if (argc!=6)
		err_sys("incorrect number of inputs.\n");
	printf("success [arg count]\n");
	//define descriptors
	int inFileDes = open(argv[1], O_RDONLY);
	int alphaDes = open(argv[2], O_RDWR | O_CREAT, 0666);
	int numDes = open(argv[3], O_RDWR | O_CREAT, 0666);
	int otherDes = open(argv[4], O_RDWR | O_CREAT, 0666);
	int copyDes = open(argv[5], O_RDWR | O_CREAT, 0666);
	//while there are characters in the input file
	while((nbyte = read(inFileDes, buffer, BUFFER_SIZE)) > 0){
		if(buffer[0]==32||buffer[0]==10){//space case
			pwrite(alphaDes, buffer, BUFFER_SIZE, offset);
			pwrite(numDes, buffer, BUFFER_SIZE, offset);
			pwrite(otherDes, buffer, BUFFER_SIZE, offset);
		}
		else if(buffer[0]>96&&buffer[0]<123){//alpha case, only lowercase
			pwrite(alphaDes, buffer, BUFFER_SIZE, offset);
		}
		else if(buffer[0]>47&&buffer[0]<58){//num case
			pwrite(numDes, buffer, BUFFER_SIZE, offset);
		}
		else{//other case
			pwrite(otherDes, buffer, BUFFER_SIZE, offset);
		}
		//iterate for pwrite functionality
		offset+=1;
	}
	offset=0;
	char copyBuffer[1];
	lseek(inFileDes, 0, SEEK_SET);
	while((read(inFileDes, buffer, 1)) > 0){
		char copyBuffer[1];
		if(copyBuffer[0]>96&&copyBuffer[0]<123){//alpha
			pread(alphaDes, copyBuffer, 1, offset);
			pwrite(copyDes, copyBuffer, 1, offset);
		}
		else if(copyBuffer[0]>47&&copyBuffer[0]<58){//num
			pread(numDes, copyBuffer, 1, offset);
			pwrite(copyDes, copyBuffer, 1, offset);
		}
		else{//other
			pread(otherDes, copyBuffer, 1, offset);
			pwrite(copyDes, copyBuffer, 1, offset);
		}
		offset+=1;
	}
	//close descriptors
	close(inFileDes);
	close(alphaDes);
	close(numDes);
	close(otherDes);
	close(copyDes);
	exit (0);
}
