#include<stdio.h>
#include<graphics.h>

void main(){

int gd,gm=VGAMAX;
int a;
gd=DETECT;

intigraph(&gd,&gm);
line(100,100,300,300);
scanf("%d",&a);
return 0;

}

