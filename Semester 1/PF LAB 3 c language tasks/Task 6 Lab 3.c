#include  <stdio.h>

int main(){
	float x1, x2, y1, y2;
	float slope;

	
	printf(" Enter x1: \n");
	scanf("%f",&x1);
	
	printf("Enter x2: \n");
	scanf("%f",&x2);
	
	printf("Enter y1: \n");
	scanf("%f",&y1);
	
	printf("Enter y2: \n");
	scanf("%f",&y2);
	

	
	slope = (y2 - y1) / (x2 - x1);
	
	printf("Slope is %.3lf", slope);
	
	return 0;
	
	
}

