#include <stdio.h>

int main()
{
	int i, n;
	char str[100];
	
	printf("\nPlease enter a string to encrypt:\n");
	gets(str);
	
	FILE *fptr;
	fptr = fopen("Encrypted.txt","w");
	
	for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3; 
		
		fwrite(str, sizeof(str), 1, fptr); 
		fclose(fptr);
		
		printf("\nTHE FILE OUTPUT IS: \n");
    	fptr = fopen("Encrypted.txt", "r");
    	fread(str, sizeof(str), 1, fptr);
    	
    	printf("Encrypted text inserted in file: %s\n", str);
    	
    	//Decryption
    	for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3;
        
        printf("\nDecrypted string after reading the file: %s\n", str);
        
        fclose(fptr);
        return 0;
		
}
