/* Logan Kelsch, Task 4, Lab 3, code mostly from notes */

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

int main()
{
    	int InFileDes1;//des for first file that will output
	int InFileDes2;//des for second file that will output
    	int OutFileDes;//des for output file
    	int nbyte;
    	char buffer[BUFFER_SIZE];
    
	//infiles, both read only
	InFileDes1 = open("task2.c",O_RDONLY);
	InFileDes2 = open("task3.c",O_RDONLY);
	//outfile
	umask(0);//umask reset
	//if first open is successful, open with read/write
	if ((OutFileDes = open("task4_out.txt", O_RDWR | O_CREAT, 0760)) < 0)
		err_sys("Creat File Open Error");
	//if lseek successfully finds end of output file, continue
	if (lseek (OutFileDes, 0, SEEK_END)== -1)
		err_sys ("lseek error 1");
	//while read is functioning properly on first file
	while (nbyte = read (InFileDes1, buffer, BUFFER_SIZE))
		if (write(OutFileDes, buffer, nbyte) != nbyte)
			err_sys("Write Error");
	//checking for proper data capture
	if (nbyte <0)
		err_sys("Read Error");
	//REPEAT CODE FOR SECOND FILE, CHECK COMMENTS ABOVE
	if (lseek (OutFileDes, 0, SEEK_END)== -1)
		err_sys ("lseek error 2");
	while (nbyte = read (InFileDes2, buffer, BUFFER_SIZE))
		if (write(OutFileDes, buffer, nbyte) != nbyte)
			err_sys("Write Error 2");
	if (nbyte <0)
		err_sys("Read Error");

    	close (InFileDes1);
	close (InFileDes2);
    	close (OutFileDes);
    	exit (0);
}

/* goodbye! */
