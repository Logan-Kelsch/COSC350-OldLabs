/* Logan Kelsch, Task 7, Lab 3 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	int tot = 0;//tallying variable for end of addition
	for (int i=1; i<argc; i++){//for each variable in command line
		char *str = argv[i];//assign variable to easier one to access
		int num = 0;//tallying variable for each individual numbers
		for (int j=0; str[j] != '\0'; j++){//for each character of the number
			if (str[j] >= 48 && str[j] <= 57){//if the character is a number on ASCII TABLE
				num = num * 10 + (str[j] - 48);//translate to actual number
			}
			else {//else statement for someone entering non-numerical variables
				break;
			}
		}
		tot+=num;//tally after each command line variable
	}
	printf("Total Output: %d",tot);//final output
	return 0;
}
