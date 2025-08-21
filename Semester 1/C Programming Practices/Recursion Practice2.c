# include <stdio.h>
int sum(int x);
int main( )
{
int result, n;
printf("Enter five digit pos int: \n");
scanf("%d",&n);
	if(n>0){
		result = sum(n);
		printf("The sum of digits is: %d",result);
	}
return 0 ;
}

int sum(int x){
	if (x != 0){
		x = (x % 10) + sum(x/10);
		return x;
	}
	else{
		return 0;
	}
}
