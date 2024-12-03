/* Logan Kelsch, Lab 5-6, Task 2 */

#include <utmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // contains required details in utmp

//error func with output
void err_sys(char* str){
	printf(str);
	exit(1);
}

//function for opening UTMP file
int openUtmpFile(){
	//opens utmp file and creates descriptor
	int utmpDes = open("/var/run/utmp", O_RDONLY);
	//check descriptor validity
	if(utmpDes == -1)
		err_sys("Open UTMP error");
	return utmpDes;
}

//main function
int main(int argc, char *argv[]){
	//bring in utmp's file descriptor
	int utmpDes = openUtmpFile();
	printf("utmp File Descriptor Value: %d\n",utmpDes);
	//creates struct from header file
	struct utmp record;
	int nbyte = 0;
	//tally for number of users found
	int userCnt = 0;
	//grabs size of record struct
	int recordSize = sizeof(record);
	//while there is data unread in utmp
	while((nbyte = read(utmpDes, &record, recordSize)) > 0){
		//print out user record
		printf("%s\n",record.ut_user);
		//if there is a tally for user count
		if(record.ut_type == USER_PROCESS)
			userCnt+=1;
	}
	printf("Number of User Process:%d\n",userCnt);
	return 0;
}
