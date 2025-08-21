#include <stdio.h>
int main (){
	int i,n,j,length;
	printf("Enter the length for array: \n");
	scanf("%d",&n);
	int arr[n];
	length = n+1;
	for(i=0;i<=n;i++){
		printf("Enter number %d:\n",i+1);
		scanf("%d",&arr[i]);
		
	
	}
	printf("The repeating elements are: \n");
	for (i=0;i<length;i++){
		for (j=i+1;j<length;j++){
		if (arr[i] == arr[j]){
			printf("%d\n",arr[i]);
			}
		}
	}
 return 0;
}
	
	
	
