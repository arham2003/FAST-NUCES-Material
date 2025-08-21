#include <stdio.h>
 
void primeFactors(int n, int c)
{
  
  
    if (n % c == 0) {
      printf("%d ", c);
      primeFactors(n/c,c);
    }
    else
      primeFactors(n,c+1);
  
  	if(n < 1)  
        return;
}
 
/* Driver code */
int main()
{
  int n = 320;
  printf("\nPrime Factors of %d using recursion\n", n);
  primeFactors(n,2);
  return 0;
}
