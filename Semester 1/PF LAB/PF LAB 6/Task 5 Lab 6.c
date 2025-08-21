#include <stdio.h>

int main (){
	int x, num, y;
	
	printf("Enter a whole number: \n");
	scanf("%d",&num);
	
	x = num > 0 ? printf("Number %d is positive.\n",num) : printf("Number %d is negative.\n",num); 
	y= (num % 2) == 0 ?  printf("Number %d is also even.\n",num) : printf("Number %d is also odd.\n",num);
	   
	return 0;
}
