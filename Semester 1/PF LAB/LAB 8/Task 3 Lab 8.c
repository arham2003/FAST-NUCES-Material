#include <stdio.h>
int main (){
	int i,n,j,max=0,min=999999;
	printf("Enter the limit for array: \n");
	scanf("%d",&n);
	int num[n];
	for(j=0;j<n;j++){
		printf("Enter number %d:\n",j+1);
		scanf("%d",&num[j]);
		
	}
	for(i=0;i<n;i++){
	
		if(num[i] > max){
			max = num[i];
		}
		if (num[i] < min){
			min = num[i];
		}
		
}
	printf("The min num is: %d\n",min);
	printf("The max num is: %d",max);
	
	
	
	return 0;
}
