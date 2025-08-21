#include <stdio.h>
int fact(int x);
int main (){
	int n,result;
	
	printf("Enter number for its factorial: \n");
	scanf("%d",&n);
	result = fact(n);
	
	printf("Factorial of Number %d is: %d",n,result);
	return 0;
}

int fact(int x){
	int i,sum=0;
	if(x == 1){
	return x;
	}
	else {	
	
		sum = x*fact(x-1);
	}
		return sum;
}
