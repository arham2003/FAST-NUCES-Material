#include <stdio.h>
#include <stlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
	int fd[2];
	// fd[0] read end
	// fd[1] write end
	if(pipe(fd) == -1 ){
		printf("Error creating pipe\n");
		return 1;
	}
	
	int id = fork();
	
	if(id == -1){
		printf("An error occurred while creating a child\n");
		return 4;
	}
	
	if (id == 0) {
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizof(int)) == -1){
			printf("Error occured with writing to the pipe.\n");
			return 2;
		}
		close(fd[1]);
	}
	else{
		close(fd[1]);
		int y;
		if(read(fd[0], &y, sizeof(int)) == -1){
			printf("Error reading from the pipe\n");
			return 3;
		}
		y= y * 3;
		close(fd[0]);
		printf("Got from child process: %d\n", y);
		
	}
}
