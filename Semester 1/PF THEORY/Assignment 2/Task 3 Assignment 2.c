#include <stdio.h>
#include <string.h>
int main()
{
	int i,n;
    char str[4];
   	char alphabets[25] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   	
   	printf("Enter 1 for Encryption or 2 for Decryption\n");
   	scanf("%d",&n);
   	switch (n){
	   case 1: // ENCRYPTION
	   	printf("Enter a 4 digit string: \n");
	   	scanf("%s",&str);
	   	strrev(str);
	   	
	   	for (i=0;i<=3;i++){
	   		
	   		switch (str[i]){
	   			case '0':
	   				str[i] = alphabets[0];
	   				break;
	   			case '1':
	   				str[i] = alphabets[1];
					break;
				case '2':
	   				str[i] = alphabets[2];
					break;
				case '3':
	   				str[i] = alphabets[3];
					break;
				case '4':
	   				str[i] = alphabets[4];
					break;
				case '5':
	   				str[i] = alphabets[5];
					break;
				case '6':
	   				str[i] = alphabets[6];
					break;
				case '7':
	   				str[i] = alphabets[7];
					break;
				case '8':
	   				str[i] = alphabets[8];
					break;
				case '9':
	   				str[i] = alphabets[9];
					break;										
			   }
		   }
	   	printf("The cypher text is: %s\n",str);
	   	break;
	   	
	   case 2: // DECRYPTION
	   		printf("Enter a string to decrypt: \n");
	   		scanf("%s",&str);
	   		strrev(str);
			printf("The decrypted text is: %s\n",str);
	   break;	
	} 
	return 0;
}
