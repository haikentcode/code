#include <graphics.h>
int main(){

int xc,yc,r;
double th,x,y;

int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);

char ch='y';
while(ch=='y')
{

printf("Enter the center \n");
scanf("%d\t%d",&xc,&yc);
printf("Enter radius\n");
scanf("%d",&r);
for(th=0;th<=3.14/4;th=th+0.01)
{
x=r*cos(th);
y=r*sin(th);
putpixel((xc+x),(yc+y),WHITE);
putpixel((xc-x),(yc+y),WHITE);
putpixel((xc-x),(yc-y),WHITE);
putpixel((xc+x),(yc-y),WHITE);
putpixel((xc+y),(yc+x),WHITE);
putpixel((xc-y),(yc+x),WHITE);
putpixel((xc-y),(yc-x),WHITE);
putpixel((xc+y),(yc-x),WHITE);

}

getchar();


}
closegraph();
}
