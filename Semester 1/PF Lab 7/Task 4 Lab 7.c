#include <stdio.h>
#include <math.h>
int main (){
	int num, i=2,isPrime,count;
	
	printf("Enter a integer value: ");
	scanf("%d",&num);
	
	printf("Prime Numbers are: \n");
	for(i=2;i<=num;i++){
		
		isPrime=1;
		for(count=2;count<i;count++){
		
			if(i % count == 0){
				isPrime = 0;
				break;
				}
				
		}
			if(isPrime)
					printf("%d\t",i);


 }
 return 0;
}
