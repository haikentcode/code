#include<stdio.h>

int main(){

   int x;
   scanf("%d",&x);

   float ans=0;

   if(x>5000)
   {

       ans=5000*0.0;
       x-=5000;

       if(x>10000){



            ans+=10000*0.01;
            x-=10000;

            if(x>20000){


                 ans+=20000*0.15;
                 x-=20000;
                 ans+=x*0.2;
                 printf("%d",x);

            }else
            {

              ans+=x*0.15;
            }




       }else
       {

         ans+=x*0.1;
       }


   }else
   {

     ans=x*0.0;

   }


   printf("ans=%f",ans);


}
