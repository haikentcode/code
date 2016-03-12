include "Noise.h"
using namespace stk;
int main()
{
  StkFloat output;
  Noise noise;
  for ( unsigned int i=0; i<20; i++ ) {
    output = noise.tick();
    std::cout << "i = " << i << " : output = " << output << std::endl;
  }
  return 0;
}