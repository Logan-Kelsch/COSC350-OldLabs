/* Logan Kelsch */
/* forkExec.c */
/* COSC 350, Lab 5-6, Task 5 */
/* Further edited for Wait portion, Lab 5-6, Task 4 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // included for wait functionality
#include <sys/types.h> // for execv of other .c file

//added error check function
void err_sys(char *str){
    printf(str);
    exit(1);
}

//added inputs to main from command line
int main(int argc, char *argv[])
{
    //command line, specific validation
    if(argc!=6)
	err_sys("Command Line Input Error\nFormat: child- message, loop, time -parent- loop, time\n");
    //I USED EVIL LIBRARY FUNCTIONS!!! NOOOOOOOOOOOOOOOOO!! NOT EVIL LIBRARY FUNCTIONS!!
    //THIS WAS AN EVIL ACT OF THE MOST EVIL! USING LIBRARY FUNCTIONS!! THIS IS NOT GOOD PROGRAMMING!!
    int Np = atoi(argv[4]);
    int Tp = atoi(argv[5]);
    pid_t pid;
    char *message;
    int n;
    int exit_code; //from page 475
    int s; //sleep time
    int execExitCode;
    printf("fork program starting\n");
    pid = vfork();
    switch(pid)
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
	    //check if execv works, run program "child" with argv arguments
	    if((execExitCode = execv("child", argv)) == -1)
		    err_sys("EXEC ERROR");
	    _exit(execExitCode);
            break;
        default:
            message = "parentMessage";
            n = Np;//set iterations to variable
            s = Tp;//added sleep time variable
            exit_code = 0; //from page 475
	    for(; n>0; n--){
		puts(message);
		printf("Parent PID: %d\n", getpid());
		sleep(s);
	    }
            break;
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
