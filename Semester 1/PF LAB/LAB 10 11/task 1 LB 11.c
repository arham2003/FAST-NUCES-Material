#include <stdio.h>
void main() 
{
   
   int i,n, sum = 0;
   int *sumPtr;

	
   printf(" Input the number of elements to store in the array (max 10) : ");
   scanf("%d",&n);
   int array1[n];
   printf(" Input %d number of elements in the array : \n",n);
   for(i=0;i<n;i++)
      {
	  printf(" element - %d : ",i+1);
	  scanf("%d",&array1[i]);
	  } 	

   sumPtr = array1; 
 
   for (i = 0; i < n; i++) {
      sum = sum + *sumPtr;
      sumPtr++;
   }
 
   printf(" The sum of array is : %d\n\n", sum);
}
