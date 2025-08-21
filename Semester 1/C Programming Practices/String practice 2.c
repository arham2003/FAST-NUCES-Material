//Find Length of a string without using library function
#include <stdio.h>

int main(){
	int i=0,count=0;
//	printf("Enter the length of string: \n");
//	scanf("%d",&n);
	char arr[20];
	
		printf("Enter Name: \n");
		gets(arr);
		
		while (arr[i] != '\0'){
			count++;
			i++;
		}
		printf("The Length is: %d",count);
		return 0;
}
