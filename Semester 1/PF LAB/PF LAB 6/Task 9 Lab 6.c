#include <stdio.h>

main (){
	int n,x;
	printf("Enter a number");
	scanf("%d",&n);
	
	x = n % 10 == 0 ? printf("Last digit Zero.") : printf("Last digit Non-zero");
	return 0;
}
	
		
	

