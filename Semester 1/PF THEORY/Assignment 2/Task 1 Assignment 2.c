#include <stdio.h>
#include <math.h>
int main (){
	int Rx1=1, Ry1=3, x2, y2,i,LSD,Location,N;
		printf("Enter least significant digit of your phone number: \n");
		scanf("%d",&LSD);
		if(LSD > 0 && LSD < 4){
			i=1;
			N = pow(2,LSD) * 2; 
			while (i<=N){
			int distance;
			printf("\nEnter value of x2 and y2: \n");
			scanf("%d %d",&x2,&y2);
			distance = sqrt(  ( (x2-Rx1)*(x2-Rx1) ) +   ( (y2-Ry1)*(y2-Ry1) )  );
			printf("distance = %d of point %d\n",distance,i);
			i++;
		}
		}
		else if (LSD == 0){
			N = pow(2,LSD)*(4+3);
			for(i=1;i<=N;i++){
			int distance;
			printf("\nEnter value of x2 and y2: \n");
			scanf("%d %d",&x2,&y2);
			distance = sqrt(  ( (x2-Rx1)*(x2-Rx1) ) +   ( (y2-Ry1)*(y2-Ry1) )  );
			printf("distance = %d of point %d\n",distance,i);
		}
		}else{
			printf("LSD should be 0 or between 0 and 4.");
		}
	return 0;
}


