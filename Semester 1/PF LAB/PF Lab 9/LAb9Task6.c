#include <stdio.h>
int gcd(int x, int y); 
int lcm(int n1, int n2,int HCF);
int main()
{
   int num1, num2, hcf=0, LCM=0;

   printf("Enter two integer Values:\n");
   scanf("%d %d", &num1, &num2);

   hcf = gcd(num1, num2);
   LCM = lcm(num1, num2, hcf);
   printf("GCD: %d", hcf);
   printf("\nLCM: %d", LCM);
   return 0;
}
//recursive function
int gcd(int x, int y)
{
   if (y == 0)   //recursion termination condition
   {
      return x;
   }
   else 
   {
      return gcd(y, x % y);   //calls itself
   }
}

int lcm(int n1, int n2,int HCF)
{
   int result=0;
   
   result = (n1 * n2) / HCF;
   
   return result;
}
