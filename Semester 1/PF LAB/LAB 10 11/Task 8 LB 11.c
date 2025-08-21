#include<stdio.h>
#include<string.h>


int main()
{
	
    
    int a=0;

    printf("Enter the array size: ");
    
	scanf("%d",&a);

    char arr[a];
    
	printf("Enter the array Elements: ");
    scanf("%s", arr);

    int *ptr1=&arr[0];
    int *ptr2=&a;

    SentenceCase(&arr[0],&a);
    

    return 0;

}

void SentenceCase(char *Text, int *size)
{
puts(Text);
}
