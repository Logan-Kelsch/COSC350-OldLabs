/* Task 3, grabbed this from textbook example 474 */
/* Further editing by Logan Kelsch, Lab 5-6, Task 3 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//added error check function
void err_sys(char *str){
    printf(str);
    exit(1);
}
//added inputs to main from command line
int main(int argc, char *argv[])
{
    //command line validation
    if(argc!=5)
	err_sys("Command Line Input Error");
    //used EVIL LIBRARY FUNCTIONS!!! NOOOOOOOOOOOOOOOOO!! NOT EVIL LIBRARY FUNCTIONS!!
    //THIS WAS AN EVIL ACT OF THE MOST EVIL! USING LIBRARY FUNCTIONS!! THIS IS NOT GOOD PROGRAMMING!!
    int Nc = atoi(argv[1]);
    int Np = atoi(argv[2]);
    int Tc = atoi(argv[3]);
    int Tp = atoi(argv[4]);
    pid_t pid;
    char *message;
    int n;
    int s; //sleep time
    printf("fork program starting\n");
    pid = fork();
    switch(pid)
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n = Nc;//set iterations to variable
	    s = Tc;//added sleep time variable
            break;
        default:
            message = "This is the parent";
            n = Np;//set iterations to variable
	    s = Tp;//added sleep time variable
            break;
    }
    for(; n > 0; n--) {
        puts(message);
        sleep(s);//switched sleep time to variable s
    }
    exit(0);
}
