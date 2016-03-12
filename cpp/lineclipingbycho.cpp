#include <iostream>
#include <graphics.h>
#include <stdio.h>
FILE *fp;
using namespace std;
class clipping
{
private:
    int x;
    int y;
    int code[4];
public:
    clipping();
    void getxy(char p[5]);
    void encode(int left,int right,int bottom,int top);
    int getcode(int k);
    float getx(void);
    float gety(void);
    friend int accept(clipping p1,clipping p2);
    friend int reject(clipping p1,clipping p2);
    friend void swap_points(clipping &p1,clipping &p2);
    int point_inside(void);
    void clipping::operator =(clipping p2);
    void changex(int winy,float m);
    void changey(int winx,float m);
};

clipping::clipping()
{
    int i;
    x = 0;
    y = 0;
    for(i=0;i<4;i++)
        code[i] = 0;
}

float clipping::getx(void)
{
    return(x);
}

float clipping::gety(void)
{
    return(y);
}

void clipping::getxy(char p[5])
{
    cout << "\nEnter the coordinates of point " << p;
    cout << "\nX :-  ";
    fscanf(fp,"%d",&x);
    cout << "\nY :-  ";
    fscanf(fp,"%d",&y);
}

void clipping::encode(int left,int right,int bottom,int top)
{
    if(x < left)
        code[0] = 1;
    else
        code[0] = 0;
    if (x > right)
        code[1] = 1;
    else
        code[1] = 0;
    if (y > bottom)
        code[2] = 1;
    else
        code[2] = 0;
    if (y < top)
        code[3] = 1;
    else
        code[3] = 0;
}

int clipping::getcode(int k)
{
    if (code[k] == 1)
        return(1);
    return(0);
}

int accept(clipping p1,clipping p2)
{
    int k;
    for(k=0;k<4;k++)
        if (p1.getcode(k) || p2.getcode(k))
            return(0);
    return(1);
}

int reject(clipping p1,clipping p2)
{
    int k;
    for(k=0;k<4;k++)
        if (p1.getcode(k) && p2.getcode(k))
            return(1);
    return(0);
}

int clipping::point_inside(void)
{
    if (code[0] || code[1] || code[2] || code[3])
        return(0);
    return(1);
}

void clipping::operator =(clipping p2)
{
    int i;
    x = p2.x;
    y = p2.y;
    for (i=0;i<4;i++)
        code[i] = p2.code[i];
}

void swap_points(clipping &p1,clipping &p2)
{
    clipping tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void clipping::changex(int winy,float m)
{
    x = x + (winy - y) / m;
    y = winy;
}

void clipping::changey(int winx,float m)
{
    y = y + (winx - x) * m;
    x = winx;
}

void main()
{
    int driver = DETECT,mode;
    initgraph(&driver,&mode,"c:\\tc\\bgi");
    clipping p1,p2,tmp;
    int left,top,right,bottom,done=0,draw=0;
    float m;
    fp = fopen("cohensut.in","r");
    clearviewport();
    p1.getxy("p1");
    p2.getxy("p2");
    left = getmaxx() / 2 - 50;
    right = getmaxx() / 2 + 50;
    bottom = getmaxy() / 2 + 50;
    top = getmaxy() / 2 - 50;
    clearviewport();
    rectangle(left,top,right,bottom);
    line(p1.getx(),p1.gety(),p2.getx(),p2.gety());
    while(done == 0)
    {
        p1.encode(left,right,bottom,top);
        p2.encode(left,right,bottom,top);
        if (accept(p1,p2))
        {
            done = 1;
            draw = 1;
        }
        elseif (reject(p1,p2))
        {
            done = 1;
        }
        else
        {
            if (p1.point_inside())
                swap_points(p1,p2);
            m = (p2.gety() - p1.gety()) / (p2.getx() - p1.getx());
            if(p1.getcode(0))
                p1.changey(left,m);
            elseif(p1.getcode(1))
                p1.changey(right,m);
            elseif (p1.getcode(2))
                p1.changex(bottom,m);
            elseif (p1.getcode(3))
                p1.changex(top,m);
        }
        cout << "\nPress any key to continue...\n";
        getch();
        clearviewport();
        rectangle(left,top,right,bottom);
        line(p1.getx(),p1.gety(),p2.getx(),p2.gety());
    }
    if (draw)
    {
        rectangle(left,top,right,bottom);
        line(p1.getx(),p1.gety(),p2.getx(),p2.gety());
    }
    getch();
}
