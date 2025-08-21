#include<stdio.h>

int main()
{
  int i,j;
  for(i=5;i>=1;i--)
  {
    for(j=1;j<=4;j++)
    {
      if(j<=i)
        printf(" %d ",j);
      else
        printf("  ");
    }
    if (i==5) {
	printf (" 5 ");
	} else {
	printf ("   ");
    }
	for(j=4;j>=1;j--)
    {
      if(j<=i)
        printf(" %d ",j);
      else
        printf("    ");
    } 
    printf("\n");
  }
  return 0;
}
