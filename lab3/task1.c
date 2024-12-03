/* Logan Kelsch, Task 1, Lab 3, code mostly from notes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*STDIN_FILENO, STDOUT_FILENO*/
#define BUFFER_SIZE 2
//error function for printout
void err_sys(char *str)
{
    printf ("%s",str);
    exit (1);
}

int main()
{
    int nbyte;
    char buffer[BUFFER_SIZE];
    //while read is taking in data of size buffer
    while ((nbyte = read(STDIN_FILENO, buffer, BUFFER_SIZE)) >0)
	//if check for unsuccessful writing to stdout file
        if (write (STDOUT_FILENO, buffer, nbyte) != nbyte)
            err_sys ("Write Error");
    //ensuring that nbyte carries data
    if (nbyte <0)
        err_sys("read Error");
    exit (0);
}

/* goodbye! */
