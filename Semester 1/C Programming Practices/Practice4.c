#include <stdio.h>
// Write a C program to reverse the digits of a given integer.
int main (){
	int i,reverse,remainder;
	
	printf("Enter the integer to reverse: \n");
	scanf("%d",&i);	


	while (i!= 0){
		remainder = i % 10;
		reverse = reverse * 10 + remainder;
		i /= 10;
	}
	printf("The reversed integer is: %d",reverse);
	return 0;
	
}
