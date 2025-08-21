#include<stdio.h>
#include<conio.h>
int main()
{
    int M_sticks = 21, User_pick, Pc_pick;
    while(M_sticks>=1){
        printf("the availabe match sticks are: %d\n", M_sticks);
        printf("pick match sticks between (1 to 4): ");
        scanf("%d", &User_pick);

        Pc_pick = 5 - User_pick;
       
        printf("Computer picks up the %d match sticks.\n", Pc_pick);
        M_sticks = M_sticks-User_pick-Pc_pick;
        if(M_sticks==1)
        {
            printf("\nYou lost .");
            break;
        }
    }
    return(0);
}
