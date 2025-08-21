#include <stdio.h>

int main()
{
    char char1;

    /* Input character from user */
    printf("Enter any character: ");
    scanf("%c", &char1);


    if(char1 >= 'A' && char1 <= 'Z')
    {
        printf("'%c' is uppercase alphabet.", char1);
    }
    else if(char1 >= 'a' && char1 <= 'z')
    {
        printf("'%c' is lowercase alphabet.", char1);
    }
    else if(char1 >= '0' && char1 <= '9')
    {
        printf("'%c' is a digit.", char1);
    }
    else
    {
        printf("'%c' is special character.", char1);
    }

    return 0;
}
