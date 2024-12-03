/* Logan Kelsch */
/* forkWait.c */
/* COSC 350, Lab 5-6, Task 4 */

/* From Page 474, Task 3, and Page 475 */
/* Further edited for Wait portion, Lab 5-6, Task 4 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // included for wait functionality

//added error check function
void err_sys(char *str){
    printf(str);
    exit(1);
}

//added inputs to main from command line
int main(int argc, char *argv[])
{
    //command line, specific validation
    if(argc!=5)
	err_sys("Command Line Input Error");
    //I USED EVIL LIBRARY FUNCTIONS!!! NOOOOOOOOOOOOOOOOO!! NOT EVIL LIBRARY FUNCTIONS!!
    //THIS WAS AN EVIL ACT OF THE MOST EVIL! USING LIBRARY FUNCTIONS!! THIS IS NOT GOOD PROGRAMMING!!
    int Nc = atoi(argv[1]);
    int Np = atoi(argv[2]);
    int Tc = atoi(argv[3]);
    int Tp = atoi(argv[4]);
    pid_t pid;
    char *message;
    int n;
    int exit_code; //from page 475
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
            exit_code = 37; //from page 475
            break;
        default:
            message = "This is the parent";
            n = Np;//set iterations to variable
            s = Tp;//added sleep time variable
            exit_code = 0; //from page 475
            break;
    }
    for(; n > 0; n--) {
	puts(message);
	sleep(s); // sleep variable switched to s
    }
    //chunk of code added waiting for the child process to finish, from page 475
    if (pid != 0){
	int stat_val;
	pid_t child_pid;

	child_pid = wait(&stat_val);

	printf("Child has finished: PID = %d\n", child_pid);
	if(WIFEXITED(stat_val))
		printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
	else
		printf("Child terminated abnormally\n");
    }
    //specific exit code as defined above
    exit(exit_code);
}

//The difference between these results and the program in task 3.

//Aside from the obvious additional printout of the finished child PID 
//and child exit code, the new section of code after the sleep for loop waits
//for the child process to end. The parent process execution is suspended
//while waiting on child to call exit.
