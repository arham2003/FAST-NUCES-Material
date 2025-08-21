#include <stdio.h>
int main()
{
int x,n;
char comDevice;
printf("Enter no. of iterations: \n");
scanf("%d",&n);
printf("Enter the device you want to communicate with: (S for S-D car or M for Mobile Device\n");
scanf(" %c",&comDevice);

if (comDevice == 'S' || comDevice == 's'){
for(x=0;x<n;x++){
printf("Move Straight\n");
}

for(x=0;x<n;x++){

printf("***\n");
printf("***Move Straight\nMove Straight\nMove Straight\nMoveStraight\nMove Straight\nMove Straight\n");

}
printf("***");
}
else if (comDevice == 'M' || comDevice == 'm'){

for (x=0;x<n;x++){
printf("Mobile is in city zone\n");
}

for(x=0;x<n;x++){

printf("**\n");
printf("**Mobile is in city zone\nMobile is in cityzone\nMobile is in city zone\nMobile is in city zone\nMobile is in city zone\nMobile is in city zone\n");

}
printf("**");

}
return 0;
}
