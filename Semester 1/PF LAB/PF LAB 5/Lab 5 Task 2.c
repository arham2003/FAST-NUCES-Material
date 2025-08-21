#include<stdio.h>
#include<math.h>

int main(){
	int num1, num2; 
	char choice;
	printf("enter numbers \n");
	scanf("%d%d",&num1,&num2);
	
	printf("press + for sum \n - for sub \n * for mul \n / for div \n");
	scanf(" %c",&choice);
	
	switch(choice){
		case '+':
			printf("sum=%d \n",num1+num2);
			break;
		case '-':	
		    printf("sub=%d \n",num1-num2);
			break;
		case '*':
		    printf("mul=%d \n",num1*num2);
			break;
		case '/':
		    printf("div=%d \n",num1/num2);
			break;
		default:
		    printf("enter choice \n");
	}
	return 0;
}
