#include <stdio.h> 
// C recursive function to solve tower of hanoi puzzle
int moves=0;
void hanoiTower(int n, int from_rod, int to_rod, int aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %d to rod %d", from_rod, to_rod);
        moves++;
        return;
    }
    hanoiTower(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %d to rod %d", n, from_rod, to_rod);
    moves++;
    
    hanoiTower(n-1, aux_rod, to_rod, from_rod);
    printf("\nNo of moves are %d ",moves);
}
    
 
int main()
{
    int n ; // Number of disks
    printf("Enter no. of disks");
    scanf("%d",&n);
    hanoiTower(n,1,2,3);  // A, B and C are names of rods
    return 0;
}
