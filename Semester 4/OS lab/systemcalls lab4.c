#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/type.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
	pid_t pid;
	
	pid = fork();
	
	if(pid < 0) { //error occurred
		fprintf(stderr, "Fork Failed");
		return 1;
	}else if (pid == 0){ // child process
		printf ("Child Process ID: %d\n", getpid());
	}
	else{
		printf("Parent process Id: %d\n", getpid());
	}
	
	
	return 0;
}
