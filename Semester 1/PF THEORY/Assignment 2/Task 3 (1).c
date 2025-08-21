#include <stdio.h>
int main (){
	int i=1,x,n,enc;
	char num,input;
	printf("E for Encryption or D for Decryption: \n");
	scanf(" %c",&input);
	switch(input){
		case 'E':
				printf("Enter the length of your string: \n");
				scanf("%d",&x);
				while(i<=x) {
					printf("input string \n");
					scanf(" %c",&num);
					enc = num+17;
					printf("encrypted: %c\n",enc);
					i++;
				}
				break;
		case 'D':
		printf("Enter the length of your encryption");
		scanf("%d",&x);
		while (i<=x){
			printf("Input Encrypted Letter(s): \n");
			scanf(" %c",&num);
			enc = num - 65;
			printf("decrypted: %c\n",enc);
			i++;
		}		
		break;
	}
	return 0;
}
