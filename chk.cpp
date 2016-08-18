#include <iostream>
   using namespace std;
   class Base
   {
       public:
       virtual void print() const = 0;
   };
   class DerivedOne : virtual public Base
   {
       public:
       void print() const
       {
           cout << "1";
       }
   };
   class DerivedTwo : virtual public Base
   {
       public:
       void print() const
       {
           cout << "2";
       }
   };
   class Multiple : public DerivedOne, DerivedTwo
   {
       public:
       void print() const
       {
           DerivedTwo::print();
       }
   };
   int main()
   {
       Multiple both;
       DerivedOne one;
       DerivedTwo two;
       Base *array[ 3 ];
       array[ 0 ] = &both;
       array[ 1 ] = &one;
       array[ 2 ] = &two;
       for ( int i = 0; i < 3; i++ )
       array[ i ] -> print();
       return 0;
   }
