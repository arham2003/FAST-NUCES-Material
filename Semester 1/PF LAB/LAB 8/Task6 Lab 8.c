#include <stdio.h>
int main (){
	int m1,n1,r,c,i,j,k;
	printf("Enter the number of rows of matrix a: \n");
	scanf("%d",&m1);
	printf("Enter the number of columns of matrix a: \n");
	scanf("%d",&n1);
	int arr1[m1][n1];
	
	for(i=0;i<m1;i++){
		for(j=0;j<n1;j++){
		printf("Enter Element [%d,%d]: \n",i+1,j+1);
		scanf("%d",&arr1[i][j]);
		}
	}
	
	printf("\nEnter the number of rows of matrix b: \n");
	scanf("%d",&r);
	printf("Enter the number of columns of matrix b: \n");
	scanf("%d",&c);
	int arr2[r][c];
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
		printf("Enter Element [%d,%d]: \n",i+1,j+1);
		scanf("%d",&arr2[i][j]);
		}
	}
	if (n1 != r) {
        		printf("Matrix is incompatible for multiplication\n");
    			}
	else if (n1 == r){
		int multiply[m1][c];
		
		for(i=0;i<m1;i++){
			for(j=0;j<c;j++){
			multiply[i][j] = 0;
			for(k=0;k<r;k++){
					multiply[i][j] += arr1[i][k] * arr2[k][j];
				}
			} 
		}
		
		printf("The Matrix after multplying elements(result matrix): \n");
		for(i=0;i<m1;i++){
		for(j=0;j<c;j++){
			printf("%d ",multiply[i][j]);
			}
			printf("\n");
		}
	}
    			
 return 0;
}
