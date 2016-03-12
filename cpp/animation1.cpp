   #include<stdio.h>
   #include<graphics.h>

   struct point {
    int x;
    int y;

   };

   void triangle(point p1,point p2,point p3){

   line(p1.x, p1.y, p2.x, p2.y);
   line(p1.x, p1.y, p3.x, p3.y);
   line(p3.x, p3.y, p2.x, p2.y);

   }

   void bezier (point p[4])
{


    for (float t = 0.0; t < 1.0; t += 0.0005)
    {
	double xt = pow (1-t, 3) * p[0].x + 3 * t * pow (1-t, 2) * p[1].x +
		    3 * pow (t, 2) * (1-t) * p[2].x + pow (t, 3) * p[3].x;

	double yt = pow (1-t, 3) * p[0].y + 3 * t * pow (1-t, 2) * p[1].y +
		    3 * pow (t, 2) * (1-t) * p[2].y + pow (t, 3) * p[3].y;

	putpixel (xt, yt, WHITE);
    }

    for (int i=0; i<4; i++)
	putpixel (p[i].x, p[i].y, YELLOW);


}


   void hut(int x,int y,int h,int k){


     rectangle(x,y,x+h,y+k);
     point p1={x,y};
     point p2={x+h/2,y-k/3};
     point p3={x+h,y};
     triangle(p1,p2,p3);
     rectangle(x+h/2-5,y+k/2,x+h/2+5,y+k/2+20);




   }

   void hiosbox(int x,int y,int h,int k){


   rectangle(x,y,h+14,k);

  int mounth=h/3;
  int mountw=k/3;
   int d=5;
   point p1={x,y+mounth};
   point p2={x+mountw/2,y+d};
   point p3={x+mountw,y+mounth};
   point p4={x+mountw/2+mountw,y+d};
   point p5={x+mountw*2,y+mounth};
   point p6={x+mountw*2+mountw/2,y+d};
   point p7={x+mountw*3,y+mounth};

   triangle(p1,p2,p3);
   triangle(p3,p4,p5);
   triangle(p5,p6,p7);

   int hutx=x+h/2;
   int huty=y+k/2;

   hut(hutx,huty,50,50);

   }


   void barish(int x,int y,int h,int k){


   for(int i=0;i<100;i++){

       putpixel(x+rand()%h,y+rand()%k,rand()%25);

   }


   }


   int main()
   {
   int i;
    int gm;
    int gd=DETECT;
    initgraph(&gd,&gm,"");

int x=10;
int y=10;
int h=200;
int k=200;

while(1){
cleardevice();
hiosbox(x,y,h,k);



  int t=0;
   for(i=0;i<25;i++)
   {

       setcolor(i);
       hiosbox(x,y,h,k);
       if(i%5==0)t++;
       setcolor(3);
       fillellipse(x+h/3+i,y+k/6-i,h/50,k/50+t);
       barish(x,y,h,k);
       setcolor(i);
       delay(100);
   point p[4]={{x+rand()%h/6,y+rand()%k/6},{x+rand()%h/6,y+rand()%k/6},{x+rand()%h/6,y+rand()%k/6},{x+rand()%h/6,y+rand()%k/6}};
   point q[4]={{x+rand()%h/7,y+rand()%k/7},{x+rand()%h/7,y+rand()%k/7},{x+rand()%h/7,y+rand()%k/7},{x+rand()%h/7,y+rand()%k/7}};

   bezier(p);
   bezier(q);
       cleardevice();
   }
}
      getch();
      closegraph();


    }
