#include<stdio.h>

void swapper(int *,int *,int *);
int main()
{

    int n1,n2,n3;
	printf("\n\n Function : swap two numbers using function :\n");
	printf("------------------------------------------------\n");	   
    printf("Please Enter 1st number : ");
    scanf("%d",&n1);
    printf("Please Enter 2nd number : ");
    scanf("%d",&n2);
	printf("Please Enter 3rd number : ");
    scanf("%d",&n3);	

    printf("Before swapping: n1 = %d, n2 = %d, n3 = %d ",n1,n2,n3);
	//pass the address of both variables to the function.
    swapper(&n1,&n2,&n3);

    printf("\nAfter swapping: n1 = %d, n2 = %d, n3 = %d \n\n",n1,n2,n3);
    return 0;
}

void swapper(int *p,int *q,int *r)
{
	//p=&n1 so p store the address of n1, so *p store the value of n1
	//q=&n2 so q store the address of n2, so *q store the value of n2

    int tmp;
    tmp = *p; // tmp store the value of n1
    *p=*q;    // *p store the value of *q that is value of n2
    *q=*r;
	*r = tmp;   // *q store the value of tmp that is the value of n1
}
