#include <stdio.h>
#include <math.h>

int main(){
	int acc=32, s=100;
	float finalvel,initialvel, x;
	
	x=2*acc*s;
	finalvel=sqrt(x);
	printf("The velocity at which the stone will hit the ground is: %f",finalvel);
	
	
	return 0;
}
