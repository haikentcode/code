/*
* ##coder=hitesh kumar regar(NITJ/2016/BTECH/CSE/12103024) <haikent codestare>
* ##date 1/1/2014 time 5:00pm to 5:44pm
* ##dedicate to my angel
*/

#include<iostream>
#include<cstdlib>
#define lp(i) (i&3)==0&&((i%25)!=0||(i&15)==0)
#include<ctime>
//#include<windows.h>

using namespace std;
int getleapyear(int year1,int year2)
{
   int lpy=0;
   for(int i=year1;i<year2;i++)

    if(lp(i))
    {
        lpy++;
    }

    return lpy;

}
int febday(int y)
{
    if(lp(y)) return 29; else return 28;
}
int getmday(int m,int y)
{
 int day=0;

 for(int i=1;i<m;i++)
 {

     switch(i)
     {
         case 1: day+=31;break;
         case 2: day+=febday(y);break;
         case 3: day+=31;break;
         case 4: day+=30;break;
         case 5: day+=31;break;
         case 6: day+=30;break;
         case 7: day+=31;break;
         case 8: day+=31;break;
         case 9: day+=30;break;
         case 10:day+=31;break;
         case 11:day+=30;break;
         case 12:day+=31;break;
     }


 }

 return day;

}

void prntday(int d)
{

    switch(d)
    {

        case 1: cout<<"sunday";break;
        case 2: cout<<"monday";break;
        case 3: cout<<"tuesday";break;
        case 4: cout<<"wednesday";break;
        case 5: cout<<"thursday";break;
        case 6: cout<<"friday";break;
        case 0: cout<<"saturday";break;

    }
}
void prntmonth(int i)
{
     switch(i)
     {
    case 1: cout<<"january";break;
    case 2: cout<<"February";break;
    case 3: cout<<"MARCH";break;
    case 4: cout<<"APRIL";break;
    case 5: cout<<"MAY";break;
    case 6: cout<<"JUNE";break;
    case 7: cout<<"JULY";break;
    case 8: cout<<"AUGUST";break;
    case 9: cout<<"SEPTEMBER";break;
    case 10: cout<<"OCTOBER";break;
    case 11: cout<<"NOVEMBER";break;
    case 12: cout<<"DECEMBER";break;
    }


}

int getday(int i,int y)
{
    int day=0;

    switch(i)
     {
         case 1: day+=31;break;
         case 2: day+=febday(y);break;
         case 3: day+=31;break;
         case 4: day+=30;break;
         case 5: day+=31;break;
         case 6: day+=30;break;
         case 7: day+=31;break;
         case 8: day+=31;break;
         case 9: day+=30;break;
         case 10:day+=31;break;
         case 11:day+=30;break;
         case 12:day+=31;break;
     }

     return day;
}

unsigned long int gettotalday(int dd,int mm,int yy)
{
     int total_leap_year;
     total_leap_year=getleapyear(1,yy);
     return (yy-total_leap_year)*365+total_leap_year*366+getmday(mm,yy)+dd;
}

void printcalender(int dd,int mm,int yy)
{

     cout<<endl<<"\t\t [[";prntmonth(mm);cout<<"/"<<yy<<"]]"<<endl;
    cout<<endl<<"SUN"<<'\t'<<"MON"<<'\t'<<"TUE"<<'\t'<<"WED"<<'\t'<<"THU"<<'\t'<<"FRI"<<'\t'<<"SAT"<<endl;
    unsigned long int total_day;
    total_day=gettotalday(1,mm,yy);
    int prespace=total_day%7;

    if(prespace==0) prespace=7;
    int rowcounter=prespace;
    prespace=prespace-1;
    for(int j=1;j<=prespace;j++) cout<<'\t';

    for(int i=1;i<=getday(mm,yy);i++)
    {
        cout<<i<<'\t';
        if(rowcounter==7){cout<<endl;rowcounter=0;}
        rowcounter++;

    }
}

int validation(int dd,int mm,int yy)
{
    if(mm<=12&&yy>0&&dd<=getday(mm,yy)&&mm>0&&dd>0) return 1; else return 0;
}


void color(int k)
       {
          // HANDLE  hConsole;
          //hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
         //SetConsoleTextAttribute(hConsole, k);
       }
 void gotoxy(int x,int y)
      {
         //function to go x,y position of console
          // COORD coord;
           //coord.X = x;
           //coord.Y = y;
           //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
      }

int main(){


             int k=0;
            //while(1)
            //{
                time_t t=time(NULL);
              tm* timePtr=localtime(&t);
              int day=timePtr->tm_mday;
              int month=timePtr->tm_mon+1;
              int year=timePtr->tm_year+1900;
              int h=timePtr->tm_hour;
              int m=timePtr->tm_min;
              int s=timePtr->tm_sec;
             for(int i=1;i<3000000;i++);

               int rday=gettotalday(1,1,2018)-gettotalday(day,month,year);



                   color(k%14);
                   gotoxy(10,6);
                   //cout<<day<<" "<<month<<" "<<year<<" "<<h<<":"<<m<<":"<<s;
                   gotoxy(10,8);
                     
                   cout<<"\n"<<rday<<" day more \n";//<<char(3)<<char(4);

                   k++;
                   if(k>=15) k=0;
            // }

           }
