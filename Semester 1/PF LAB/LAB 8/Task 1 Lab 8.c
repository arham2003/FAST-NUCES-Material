#include <stdio.h>
int main (){
	int i,j,sum=0;
	printf("Enter the limit for array: ");
	scanf("%d",&j);
	int num[j];
	for(i=0;i<j;i++){
		printf("Enter number %d:",i+1);
		scanf("%d",&num[i]);

	}
	for(i=0;i<j;i++){
				sum = sum + num[i];
	}
	printf("The Sum is: %d",sum); 
	
	return 0;
}
