/* Logan Kelsch, Task 2, Lab 4 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1

void err_sys(char *str)
{
	printf("%s",str);
	exit(1);
}

int main( int argc, char* argv[])
{
	//declare variables
	int charOffset = 0;
	char buffer[BUFFER_SIZE];
	int nbyte;
	char num[80]; //ensure only one command line input
	if(argc!=2)
		err_sys("Command line input error");
	//define descriptor
	int inFileDes = open(argv[1],O_RDONLY);
	//while there is more data in the input file
	while((nbyte = read(inFileDes, buffer, BUFFER_SIZE)) > 0){
		char asciiBuffer = buffer[0];
		if(asciiBuffer > 47 && asciiBuffer < 58){
			num[charOffset]= asciiBuffer;
			charOffset+=1;
		}
	}
	printf(num);
	int intNum = 0;
	//myatoi function
	for(int i=0;i<charOffset;i++){
		intNum = intNum*10 + (num[i]-48);
	}
	//add 10 to value
	intNum+=10;
	int strSize = charOffset;
	charOffset = 0;
	char strNum[strSize];
	int tmp = 0;
	//convert int to string
	printf("converting integer to string\n");
	while(intNum>0){
		tmp = intNum;
		while(tmp>9)
			tmp/=10;
		strNum[charOffset] = tmp+48;
		printf("building%s",strNum);
		charOffset+=1;
		intNum/=10;
	}
	//print to console
	printf("printing to console\n");
	write(STDOUT_FILENO, strNum, sizeof(strSize)-1);





	close(inFileDes);
	exit(0);
}
