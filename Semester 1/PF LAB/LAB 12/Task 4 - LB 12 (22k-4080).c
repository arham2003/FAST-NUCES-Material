#include <stdio.h>
#include <stdlib.h>
struct studentDB{
   char name[50];
};
int main(){
    struct studentDB arr1[5];  
    FILE *fptr;
    int i;

    fptr = fopen("file.txt","w");
    for(i = 0; i < 5; ++i)
    {
        fflush(stdin);
        printf("Enter name: ");
        gets(arr1[i].name);
    }

    fwrite(arr1, sizeof(arr1), 1, fptr);
    fclose(fptr);
	
	printf("\nTHE FILE OUTPUT IS: \n");
    fptr = fopen("file.txt", "r");
    fread(arr1, sizeof(arr1), 1, fptr);
    for(i = 0; i < 5; ++i)
    {
        printf("Name: %s\n", arr1[i].name);
    }
    fclose(fptr);
}
