#include <stdio.h>
#include <math.h>
int main (){
	int num1, rem;
	
	printf("Enter a Number to check: \n");
	scanf("%d",&num1);
	
	rem= num1%3;
	
	if (rem == 0){
		printf("The number is a multiple of 3.");
		
		}
		else{
		
			printf("The number is NOT a multiple of 3.");
		}
		return 0;	
}
	

	

