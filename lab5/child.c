/* Logan Kelsch, Lab 5-6, Task 5 */
/* Child Process File */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
//error printout function
void err_sys(char *str){
	printf(str);
	exit(1);
}
//main function does nothing unique, is replicating child process in previous task
int main(int argc, char *argv[]){
	int Nc = atoi(argv[2]);
	int Tc = atoi(argv[3]);
	for(; Nc > 0; Nc--){
		puts(argv[1]);
		printf("Child PID: %d\n", getpid());
		sleep(Tc);
	}
	return 37;
}
