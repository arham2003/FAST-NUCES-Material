#include <stdio.h>
int main (){
	int m1,n1,i,j,b,sum=0;
	printf("Enter the number of rows of matrix a: \n");
	scanf("%d",&m1);
	printf("Enter the number of columns of matrix a: \n");
	scanf("%d",&n1);
	printf("Enter order of square matrix: \n");
	scanf("%d",&b);
	int arr1[m1][n1];
	
	for(i=0;i<m1;i++){
		for(j=0;j<n1;j++){
		printf("Enter Element [%d,%d]: \n",i+1,j+1);
		scanf("%d",&arr1[i][j]);
		}
	}
	
	for(i=0;i<b;i++){
		sum = sum + arr1[i][i];
	}
		printf("\n trace of the matrix: %d",sum);
 return 0;
}
