#include  <stdio.h>

int main(){
	int  T, principal;
	float rate, interest;
	
	printf("Enter Principal\n");
	scanf("%d",&principal);
if (principal <= 100000 && principal >= 100){
		printf("Enter Rate\n");
		scanf("%f",&rate);
		
	if (rate >=5 || rate <= 10){
			printf("Enter period\n");
			scanf("%d",&T);
			
			if (T >= 1 || T <= 10){
				
				interest = (principal * rate * T) / 100;
				printf("interest is %f",interest);
			}
	}
		
	
}

else  {
	printf("Value is in between 100 and 1000000");
}


}

