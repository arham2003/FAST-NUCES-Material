#include <stdio.h>
#include <stdlib.h>
void swap (char *a, char *b)
{
      char temp = *a;
      *a = *b;
      *b = temp;
}
void permutation (char s[], int x, int y)
{
      int i;
   if (x == y)
      {
            printf( "%s\n", s);
      }
  else
      {
            for (i = x; i <= y; i++)
            {
                    swap (&s[x], &s[i]);
                    permutation (s, x + 1, y);
                    swap (&s[x], &s[i]);
            }
      }
}
int main ()
{
	int i,n;
		printf("Enter String Amount: \n");
		scanf("%d",&n);
      char s[10],str[20] ;
		for (i=1;i<=n;i++){
      printf(" Enter string %d: ",i);
      scanf(" %s",str);
      printf ("string is %s\n", str);
      printf ("Permutations are: \n");
      permutation (str, 0, 2); // restricted to 2
		}
      return 0;
}
