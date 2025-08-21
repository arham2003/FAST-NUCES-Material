#include <stdio.h>
int main (){
	int i,j;
	printf("Enter the limit for array: \n");
	scanf("%d",&j);
	int num[j];
	for(i=0;i<j;i++){
		printf("Enter number %d:\n",i+1);
		scanf("%d",&num[i]);

	}
	printf("The reversed array is: \n");
	for(i=j-1;i>=0;i--){
			
				printf("%d\n",num[i]);
	}
	
	
	return 0;
}
