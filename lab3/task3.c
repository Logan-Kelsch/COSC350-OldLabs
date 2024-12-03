/* Logan Kelsch, Task 3, Lab 3, code mostly from notes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*STDIN_FILENO, STDOUT_FILENO*/
#include <fcntl.h>

#define BUFFER_SIZE 32

void err_sys(char *str)
{
	printf ("%s",str);
	exit (1);
}

int main()
{
    	int InFileDes;
    	int OutFileDes;
    	int nbyte;
    	char buffer[BUFFER_SIZE];//buffer of custom size
    
	//infile, opened read only
	InFileDes = open("task3.c",O_RDONLY);
	//outfile
	umask(0);//umask reset
	//opened write only to create, full access
	OutFileDes = open("task3_out.txt", O_WRONLY|O_CREAT, 0777);
	//while read is successfully taking in data
	while (nbyte = read (InFileDes, buffer, BUFFER_SIZE))
		//checking for faulty data writing
		if (write(OutFileDes, buffer, nbyte) != nbyte)
			err_sys("Write Error");
	//ensuring proper data capture into nbyte
	if (nbyte <0)
		err_sys("Read Error");
    	close (InFileDes);
    	close (OutFileDes);
    	exit (0);
}

/* goodbye! */
