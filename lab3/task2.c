/* Logan Kelsch, Task 2, Lab 3, code mostly from notes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*STDIN_FILENO, STDOUT_FILENO*/
#include <fcntl.h>


int main()
{
    int InFileDes;//infile descriptor
    int OutFileDes;//outfile descriptor
    char Ach;//character to move
    
    //infile, opened read only
    InFileDes = open("task2.c",O_RDONLY);
    //outfile, opened write only, access is 0600
    OutFileDes = open("task2_out.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    //while read successfully takes one by one bytes
    while (read (InFileDes, &Ach, 1) == 1)
	    write(OutFileDes, &Ach, 1);
    close (InFileDes);
    close (OutFileDes);
    exit (0);
}

/* goodbye! */
