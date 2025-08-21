#include <stdio.h>
int main(){
	int side1,side2,side3;
	
	printf("Enter first side: \n");
	scanf("%d",&side1);
	printf("Enter second side: \n");
	scanf("%d",&side2);
	printf("Enter third side: \n");
	scanf("%d",&side3);
	
	if (side1 == side2 && side2 == side3 && side1 == side3){
		printf("This is an equilateral triangle.");
	}
	else if (side1 == side2 && side2 == side3 || side1 == side3  ||  side1 == side2 || side2 == side3 && side1 == side3){
		printf("This is an isosceles triangle.");
	}
	else {
		printf("This is an scalene triangle.");
	}

	
	return 0;
}
