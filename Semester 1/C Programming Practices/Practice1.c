//Write a C program to check two given integers, and return true if one of them is 30 or if their sum is 30.
#include <stdio.h>
int main(){
    printf("%d",test(25, 5));
    printf("\n%d",test(20, 30));
    printf("\n%d",test(20, 25));
    return 0;
    }    
   int test(int x, int y)
        {
            return x == 30 || y == 30 || (x + y == 30);
        }
