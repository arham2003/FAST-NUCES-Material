// Write a C program to get the absolute difference between n and 51. 
//If n is greater than 51 return triple the absolute difference.
#include <stdio.h>
int main(){
    //Absolute difference means 
	//The difference, taken without regard to sign, between the values of two variables; and in particular of two random variables
    
	printf("absolute difference is: %d",test(53));
    printf("\nabsolute difference is: %d",test(30));
    printf("\nabsolute difference is: %d",test(51));
    return 0;
    }   
	 
    int test (int n){
    	const int x= 51;
    	
    	if (n > x){
    		return (n-x)*3;
		}
		return x-n;
	}
