/* Logan Kelsch, Task 8, Lab 3, code mostly from notes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*STDIN_FILENO, STDOUT_FILENO*/
#include <fcntl.h>

#define BUFFER_SIZE 1

void err_sys(char *str)
{
    printf ("%s",str);
    exit (1);
}

int main(int argc, char *argv[])
{
    char buffer[BUFFER_SIZE];
    int InFileDes;
    int OutFileDes;
    int asciiVal;//int variable to temporarily convert data to ascii
    char* n1 = argv[1];//name of first file
    char* n2 = argv[2];//name of outfile
    char bufOut[8];//custom buffer for ascii characters

    InFileDes = open(n1,O_RDONLY);//opening input file as read only
    OutFileDes = open(n2, O_RDWR | O_CREAT, 0666);//creating output file
    //ensuring lseek can go to front of the input file
    if(lseek(InFileDes, 0, SEEK_SET)==-1)
	    err_sys("lseek error");
    //ensuring successful reading
    while (read(InFileDes, buffer, 1)==1){
	asciiVal = (int)buffer;//cast character to ascii value
	sprintf(bufOut,"%ld",asciiVal);//switch ascii value to character array
        write(OutFileDes, bufOut, 8);//write character array to file
    }
    exit (0);
}

/* goodbye! */
