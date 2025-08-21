#include <stdio.h>
#include <math.h>
int main() {
		int a = 15, b = 30;
			printf("The values of a (before): %d and b (before): %d\n",a,b);
		
		
		a=a^b;
		b=a^b;
		a=a^b;
		
		printf("New values of a: %d and b: %d",a,b);
		
	
	return 0;
	
}
