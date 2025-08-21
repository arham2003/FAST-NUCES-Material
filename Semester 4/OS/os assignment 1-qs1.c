#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define read_end 0
#define write_end 1
int main(int argc, char *argv[]){
	int fd2[2];
	pid_t pid1;
	
	if (argc < 2) {
        printf("No arguments passed for %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
	
	if(pipe(fd2) == -1){ // only for pid2
		fprintf(stderr, "Pipe failed");
		return 1;
	}
	pid1 = fork();
	
	if(pid1 < 0){
		fprintf(stderr, "Fork failed");
		return 1;
	}else if(pid1 == 0){
		 printf("PID1: Command line arguments:\n");
		 
		 for(int i=1; i<argc; ++i){
		 	printf("%s\n", argv[i]);
		 }
		 exit(EXIT_SUCCESS);
	}
	else{ //parent process
		pid_t pid2 = fork();
		
		if(pid2 < 0){
			fprintf(stderr, "Fork didn't happen");
			return 1;
		}
		else if (pid2 == 0){
			close(fd2[read_end]);
			dup2(fd2[write_end], STDOUT_FILENO);
			close(fd2[write_end]);
			
			execvp(argv[1], &argv[1]);
		}else{
			pid_t pid3 = fork();
			
			if(pid3 < 0){
				fprintf(stderr, "fork failed");
				exit(EXIT_FAILURE);
			}else if(pid3 == 0){// child process 3
				
				execl("./ex2" , "ex2.c", NULL);
				
			}else{
				close(fd2[write_end]);
				
				char buffer[4096];
			    ssize_t bytes_read;
			    
			    printf("PID2 Output:\n");
			    while ((bytes_read = read(fd2[read_end], buffer, sizeof(buffer))) > 0) { //parent now reads the data from pipe in pid2
			        write(STDOUT_FILENO, buffer, bytes_read);
			    }
			
			    close(fd2[read_end]);

			    wait(NULL);
			    wait(NULL);
			    wait(NULL);
			    
			    return 0;
			}
			
			
			
		}
		
		
	}
	
	
	return 0;
}
