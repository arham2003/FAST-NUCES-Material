#include <stdio.h>
int main (){
	int m,n,i,j;
	printf("Enter the number of rows: \n");
	scanf("%d",&m);
	printf("Enter the number of columns: \n");
	scanf("%d",&n);
	int arr1[m][n];
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		printf("Enter Element [%d,%d]: \n",i+1,j+1);
		scanf("%d",&arr1[i][j]);
		}
	}
	printf("Transpose Matrix is: \n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",arr1[j][i]);
		}
		printf("\n");
	}
	
 return 0;
}
