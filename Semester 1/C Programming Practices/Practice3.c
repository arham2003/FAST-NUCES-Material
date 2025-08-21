#include <stdio.h>
int main(){
	//Write a C program to compute the sum of the two given integer values. 
	//If the two values are the same, then return triple their sum.
    printf(" %d",sum(2,1));
    printf("\n %d",sum(2,2));
    
    return 0;
    }    
    int sum (int a,int b){
    	int result;
    	result = a+b;
    	
    	if (a == b){
    		return result*3;
		}
		return result;
	}
