#include <graphics.h>


struct  point
{
	float x, y;
};


void psub(point p1,point p2,point &p3){

	p3.x=p1.x-p2.x;
	p3.y=p1.y-p2.y;
}

int mul(point p1,point p2){

	return(p1.x*p2.x+p1.y*p2.y);
}

int main(){



int gd = DETECT,gm;

initgraph(&gd,&gm,NULL);
point p1,p2;
point l1,l2;

p1.x=100;
p1.y=100;
p2.x=300;
p2.y=300;

l1.x=80;
l1.y=130;
l2.x=330;
l2.y=150;

rectangle(p1.x, p1.y,p2.x,p2.y);
//line(l1.x,l1.y, l2.x,l2.y);

point n[4];
point p[4];
point w[4];
point d[4];

n[0].x=-1;n[0].y=0;
n[1].x=-1;n[1].y=0;
n[2].x=0;n[2].y=1;
n[3].x=0;n[3].y=-1;

p[0].x=p1.x;p[0].y=p1.y;
p[1].x=p2.x;p[1].y=p2.y;
p[2].x=p1.x;p[2].y=p1.y;
p[3].x=p2.x;p[3].y=p2.y;

psub(l1,p[0],w[0]);
psub(l1,p[1],w[1]);
psub(l1,p[2],w[2]);
psub(l1,p[3],w[3]);

for(int i=0;i<4;i++)
	 {
	 	 d[i].x=l2.x-l1.x; 
	 	 d[i].y=l2.y-l1.y;
	 }



int nw[4];
int nd[4];

for(int i=0;i<4;i++){

	nw[i]=mul(n[i],w[i]);
	nd[i]=mul(n[i],d[i]);

 }


 float tl=-10000;
 float tu=10000;


 for(int i=0;i<4;i++)
 {
   
   if(nd[i]>0)
     {
     	float tm=nw[i]/nd[i];
     	  
     	  if(tm>tl) tl=tm;
     }
     else
     {
        
       float tm=nw[i]/nd[i];
       
       if(tm<tu) tu=tm;

     }


 }

point rp1;
point rp2;

rp1.x=l1.x+d[0].x*tl;
rp1.y=l1.y+d[0].y*tl;

rp2.x=l1.x+d[0].x*tu;
rp2.y=l1.y+d[0].y*tu;


line(rp1.x,rp1.y, rp2.x,rp2.y);

delay(10000);
closegraph();

return 0;
}