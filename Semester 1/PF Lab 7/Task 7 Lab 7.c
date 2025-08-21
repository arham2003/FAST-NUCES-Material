#include <stdio.h>  
  
int main()  
{  
    int num, count , remainder, sum;  
  
    for(count=1;count <= 500;count++)  
    {  
        num = count;  
        sum = 0;  
  
        while(num)  
        {  
            remainder = num % 10;  
            sum = sum + (remainder * remainder * remainder);  
            num = num / 10;  
        }  
  
        if(count == sum)  
        {  
            printf("%d is a Armstrong number\n", count);  
        }  
		  
    }  
  
     return 0;  
}
