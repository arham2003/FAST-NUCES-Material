#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char* argv[]){
	if(mkfifo("myfifo1", 0777) == -1){
		if(errno != EEXIST){
			printf("Could not create fifo\n");
			return 1;
		}
	}
	
	printf("Opening..\n");
	int fd = open("mkfifo1", O_WRONLY);
}
