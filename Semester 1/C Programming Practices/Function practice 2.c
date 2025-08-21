// Function with Argument With No Retrun 
# include <stdio.h>
void message1( ) ;
void message2( ) ;
int main( )
{
	int s;
message1( ) ;
message2( ) ;
s= message1();
printf("The output is none. %d",s);
return 0 ;
}
void message2( )
{
printf ( "But the butter was bitter\n" ) ;
}
void message1( )
{
	int a,b,s;
	printf ( "Mary bought some butter\n" ) ;
	scanf("%d %d",&a,&b);
	s=a+b;
	
}
