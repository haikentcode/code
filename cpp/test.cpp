 #include <stdio.h>
 int &fun(){
     int static a=10;
   return a;
   
}
 int main()
 {
   
   fun()=30;
   printf("%d\n", fun());
 }
