/* Logan Kelsch, Task 5, Lab 3, code mostly from notes */

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

int main(int argc, char* argv[])
{
    	int InFileDes;
    	int OutFileDes;
    	int nbyte;
	int offset = -1;//variable that is used for exact scaling through file for reversal
    	char buffer[BUFFER_SIZE];
    
	//infiles, opened read only
	InFileDes = open(argv[1],O_RDONLY);
	//outfile
	umask(0);//umask reset
	//file opened read/write, checking for success
	if ((OutFileDes = open(argv[2], O_RDWR | O_CREAT, 0760)) < 0)
		err_sys("Creat File Open Error");
	//check for if lseek can successfully find the end of copying file
	if ((offset = lseek (InFileDes, 0, SEEK_END))== -1)
		err_sys ("lseek error 1");
	//while descriptor of copy file has not reached front of the file
	while (offset > -1)
	{	
		//if lseek propely can move to offset location
		if (lseek (InFileDes, offset, SEEK_SET)== -1)
			err_sys("lseek error 2");
		//read in data accordingly
		nbyte = read(InFileDes, buffer, BUFFER_SIZE);
		//ensure data writing properly
		if (write(OutFileDes, buffer, nbyte) != nbyte)
			err_sys("Write Error");
		//shift offset for next while loop iteration, at end to ensure no segmentation fault
		offset-=1;
	}
	if (nbyte <0)
		err_sys("Read Error");

    	close (InFileDes);
    	close (OutFileDes);
    	exit (0);
}

/* goodbye! */
