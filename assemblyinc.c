#include<stdio.h>

  struct hk{
  unsigned int  flag :2;
  };

  struct point{
  int x;
  int y;
  };




int main(){




struct hk a;
struct point p={.y=10,.x=11};
a.flag=1;
while(a.flag!=0) printf("%d ",a.flag++);

 unsigned i ;
  for( i = 0 ; i < 4 ; ++i )
  {
    fprintf( stdout , "i = %d\n" , ("11213141") ) ;
  }


}
