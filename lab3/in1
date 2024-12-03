/* Logan Kelsch, Task 6, Lab 3, code mostly from notes */

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
	int offset = -1;
    	char buffer[BUFFER_SIZE];
    
	//infiles, opened read only
	InFileDes = open(argv[1],O_RDONLY);
	//outfile
	umask(0);//umask reset
	//output file opened read/write, checking for success
	if ((OutFileDes = open(argv[2], O_RDWR | O_CREAT, 0760)) < 0)
		err_sys("Creat File Open Error");
	//checking if lseek can find end of file
	if ((offset = lseek (InFileDes, 0, SEEK_END))== -1)
		err_sys ("lseek error 1");
	//while offset has not reached the front of the file
	while (offset > -1)
	{	
		//taking in data with pread, offset adjusted at end of while loop
		nbyte = pread(InFileDes, buffer, BUFFER_SIZE, offset);
		//checking for successful writing
		if (write(OutFileDes, buffer, nbyte) != nbyte)
			err_sys("Write Error");
		offset-=1;//increment towards front of file
	}
	if (nbyte <0)
		err_sys("Read Error");

    	close (InFileDes);
    	close (OutFileDes);
    	exit (0);
}

/* goodbye! */
