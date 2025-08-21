#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define read_end 0
#define write_end 1

void fun_collatzConjecture(int n) {
    while (n != 1) {
        printf("%d, ", n);
        if (n % 2 == 0) {
            // n is even, divide it by 2
            n /= 2;
        } else {
            //n is odd, multiply it by 3 and add 1
            n = 3 * n + 1;
        }
    }
    printf("1\n");
}

int main(int argc, char *argv[]){
	int fd[2];
	pid_t pid1;
	
	if (argc < 2) {
	        printf("No arguments passed for %s\n", argv[0]);
	        exit(EXIT_FAILURE);
	    }
		
		if(pipe(fd) == -1){
			fprintf(stderr, "Pipe failed");
			return 1;
		}
		pid1 = fork();
		
		if(pid1 < 0){
			fprintf(stderr, "Fork failed");
			return 1;
		}else if(pid1 == 0){
			 printf("value passed for collatzConjecture:\n");
			 
			 	printf("%s\n", argv[1]);
			 	fun_collatzConjecture( atoi(argv[1]) );
			 	
			 exit(EXIT_SUCCESS);
		}
		else{ 
		
			close(fd[read_end]);
			close(fd[write_end]);
			
			wait(NULL);
			
			return 0;
		}
	
}
