#include<stdio.h>
int main() 
{
  //Initializing variables
  char str[100] = "str ing game";
  int length = 0,i;
  
  //Calculating length.
  length = strlen(str);
  //capitalize first character of words
	for(i=0; i<length; i++)
	{
		//check first character is lowercase alphabet
		if(i==0)
		{
			if((str[i]>='a' && str[i]<='z'))
				str[i]=str[i]-32; //subtract 32 to make it capital
			continue; //continue to the loop
		}
		if(str[i]==' ')//check space
		{
			//if space is found, check next character
			++i;
			//check next character is lowercase alphabet
			if(str[i]>='a' && str[i]<='z')
			{
				str[i]=str[i]-32; //subtract 32 to make it capital
				continue; //continue to the loop
			}
		}
		else
		{
			//all other uppercase characters should be in lowercase
			if(str[i]>='A' && str[i]<='Z')
				str[i]=str[i]+32; //subtract 32 to make it small/lowercase
		}
	}
	
	printf("Capitalize string is: %s\n",str);
	
	return 0;
}

