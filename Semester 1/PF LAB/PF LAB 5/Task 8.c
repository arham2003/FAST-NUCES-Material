#include <stdio.h>
int main(){
	int n;
	
	printf("Enter a postive integer: \n");
	scanf("%d",&n);
	
	if (n>0){
				switch (n) {
					case 1:
						printf("one\n");
						break;
					case 2:
						printf("two\n");
						break;
					case 3:
						printf("three\n");
						break;
					case 4:
						printf("four\n");
						break;
					case 5:
						printf("five\n");
						break;
					case 6:
						printf("six\n");
						break;
					case 7:
						printf("seven\n");
						break;
					case 8:
						printf("eight\n");
						break;
					case 9:
						printf("nine\n");
						break;
					default:
					printf("9\n");									
				}
	}
	else {
		printf("enter a positive integer.");
	}
	
	return 0;
}
