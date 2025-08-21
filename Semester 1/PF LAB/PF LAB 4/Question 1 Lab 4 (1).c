#include <stdio.h>
#include <math.h>
#define pi  3.1428
int main(){
	
	float length1, angle1, height1,radian1;
	float length2, angle2, height2,radian2;
	float length3, angle3, height3,radian3;
	float length4, angle4, height4,radian4;
	
	printf("Enter the first length and angle in degrees\n");
	scanf("%f %f",&length1,&angle1);
	
	if (angle1 < 90){
	radian1 = (pi * angle1) / 180;
	height1 = length1 * sin(radian1);
	
	printf("The height for first length and angle is: %.3lf\n\n",height1);
		
}

else {
	printf("Enter angle less than 90");
}	


		
			printf("Enter the second length and angle in degrees\n");
			scanf("%f %f",&length2,&angle2);
	
			if (angle2 < 90){
			radian2 = (pi * angle2) / 180;
			height2 = length2 * sin(radian2);
	
			printf("The height for second length and angle is: %.3lf\n\n",height2);
		
			}
			else {
			printf("Enter angle less than 90");
			}
			
			
			printf("Enter the third length and angle in degrees\n");
			scanf("%f %f",&length3,&angle3);
	
			if (angle3 < 90){
			radian3 = (pi * angle3) / 180;
			height3 = length3 * sin(radian3);
	
			printf("The height for third length and angle is: %.3lf\n\n",height3);
		
			}
			else {
			printf("Enter angle less than 90");
			}
			
			
			
			
			printf("Enter the third length and angle in degrees\n");
			scanf("%f %f",&length4,&angle4);
	
			if (angle4 < 90){
			radian4 = (pi * angle4) / 180;
			height4 = length4 * sin(radian4);
	
			printf("The height for fourth length and angle is: %.3lf\n\n",height4);
		
			}
			else {
			printf("Enter angle less than 90");
			}
			
			
		
	
	
}
