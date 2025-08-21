#include <stdio.h>
#include <math.h>
int main (){
	int num, i,j;
	printf("Enter Number");
	scanf("%d",&num);
	
	for(i=num;i>=num;i--){
		
		for(j=1;j<=i;j++){
			printf("%d",num);
		}
		printf("\n");
		if(num>0){
		
		num=num-1;
		}
	}
 return 0;
}
