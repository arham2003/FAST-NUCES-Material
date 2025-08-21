#include <stdio.h>

int main(){
	float rad,vel;
	int angspeed=10;
	printf("Enter the radius:");
	scanf("%f",&rad);
	vel =angspeed*rad;
	printf("The angular velocity: %.3lf",vel);
	
	return 0;
}
