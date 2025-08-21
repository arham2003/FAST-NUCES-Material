#define PALLEN 2

#include <stdio.h>
#include <string.h>

int a[10][10];

/*int a[5][5] = {
        { 1, 2, 1, 3, 5 } ,
        { 4, 5, 6, 7, 4 } ,
        { 4, 5, 5, 4, 1 } ,
        { 1, 9, 2, 1, 4 } ,
        { 1, 9, 4, 1, 5 }
};*/
int n=0;

void checkPalindrome(char*);
void diagonalPal();
void stringSpliter(char*);

int main() {

    int i, j, k, l, x;
    int c = 0;
    int jmp;
    int ptr = 0;

    int diag;

    char recycler[20];
    char diaglist[25];
    char revdiaglist[25];

    system("cls");

    printf("\nEnter the dimension (n) of this square matrix i.e. (n*n) - ");
    scanf("%d", &n);

    printf("\nNow enter the elements for this %d*%d matrix - ", n,n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);



    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("-%d-", a[i][j]);
        }
        printf("\n");
    }


    printf("\nRow Palindromes");
    for (i = 0; i < n; i++) {
        for (j = n-1, k = PALLEN; j > 0; j--, k++) {
            while (c < j) {
                jmp = c;
                memset(recycler, 0, 20);
                ptr = 0;
                for (l = 0; l < k; l++) {
                    recycler[ptr] = a[i][jmp]; //0,0 -- 0,1
                    ptr++;
                    jmp++;
                }
                checkPalindrome(recycler);
                c++;
            }
            c = 0;
        }

    }

    printf("\n\nColumn Palindromes");
    for (i = 0; i < n; i++) {
        for (j = n-1, k = PALLEN; j > 0; j--, k++) {
            while (c < j) {
                jmp = c;
                memset(recycler, 0, 20);
                ptr = 0;
                for (l = 0; l < k; l++) {
                    recycler[ptr] = a[jmp][i]; //0,0-- 1,0
                    ptr++;
                    jmp++;
                }
                checkPalindrome(recycler);
                c++;
            }
            c = 0;
        }
    }

	return 0;

}

void stringSpliter(char *a){

    int i,j,k,ptr,jmp,c=0,l;
    int len;
    len = strlen(a);

    char recycler[20];

    for (j = len-1, k = PALLEN; j > 0; j--, k++) {
        while (c < j) {
            jmp = c;
            memset(recycler, 0, 20);
            ptr = 0;
            for (l = 0; l < k; l++) {
                recycler[ptr] = a[jmp]; //0,0 -- 0,1
                ptr++;
                jmp++;
            }
            checkPalindrome(recycler);
            c++;
        }
        c = 0;
    }

}


void checkPalindrome(char *string){

    int isPalindrome = 1, i=0;
    char rev[20];

    strcpy(rev, string);
    strrev(rev);

    isPalindrome = strcmp(rev, string);

    if(isPalindrome == 0){
        printf("\n");
        while(string[i]!='\0') 
		{
		 printf("%d", string[i++]);
		 } 
    }

}

