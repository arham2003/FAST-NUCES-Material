#include<stdio.h>

//void swap(int *,int *);
int main()
{

    int n1,n2;
	printf("\n\n Function : swap two numbers using function :\n");
	printf("------------------------------------------------\n");	   
    printf("Input 1st number : ");
    scanf("%d",&n1);
    printf("Input 2nd number : ");
    scanf("%d",&n2);	

    printf("Before swapping: n1 = %d, n2 = %d ",n1,n2);
	//pass the address of both variables to the function.
    swap(&n1,&n2);

    printf("\nAfter swapping: n1 = %d, n2 = %d \n\n",n1,n2);
    return 0;
}

void swap(int p,int q)
{
	//p=&n1 so p store the address of n1, so p store the value of n1
	//q=&n2 so q store the address of n2, so q store the value of n2

    int tmp;
    tmp = p; // tmp store the value of n1
    p=q;    // p store the value of q that is value of n2
    q=tmp;   // q store the value of tmp that is the value of n1
}
