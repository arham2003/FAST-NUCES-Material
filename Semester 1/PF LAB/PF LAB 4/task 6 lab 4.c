#include <stdio.h>
#include <math.h>
int main() {
	float t,w,finalv,y,dis,v,angle,x,pi=22/7,xangle,yangle;
	printf("Provide the angle of throw: ");
	scanf("%f",&angle);
	printf("Enter Distance of building: ");
	scanf("%f",&dis);
	printf("Enter the initial velocity of the figure: ");
	scanf("%f",&v);
	
	angle = angle*(pi/180);
	xangle= cos(angle);
	yangle= sin(angle);
	t=dis/(v*xangle);
	x=v*xangle;
	y=v*yangle+(-9.8*t);
	w=(x*x)+(y*y);
	finalv=sqrt(w);
	
	printf("The Final velocity is: %f",finalv);
	
	
	return 0;
	
}
