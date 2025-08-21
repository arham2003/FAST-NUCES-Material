#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define str_size 100 

void main()
{
    char wordStr[str_size];
    int i, word;

       printf("Input the wordString : \n");
       fgets(wordStr, sizeof wordStr, stdin);	
	
    i = 0;
    word = 1;

    while(wordStr[i]!='\0')
    {
        /* check whether the current character is white space or new line or tab character*/
        if(wordStr[i]==' ' || wordStr[i]=='\n' || wordStr[i]=='\t')
        {
            word++;
        }

        i++;
    }

    printf("Total number of words in the string is : %d\n", word-1);
}
