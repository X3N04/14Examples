//
// doubleLoop.cpp
//
// Keith Mehl
// 10/26/2005
// CSCI-14 example program
// Illustrate problems with using floating point numbers
// as loop control variables
//
#include <iostream>
#include <iomanip>
#include <cstdlib>  // for system()
using namespace std;

int main()
{
   double x;
   int i = 1;
   for( x = 0.0; x != 10.0; x += 1.0 ) // executes 10 times
   {
      cout << "count " << setw(2) << i++ << ' ' << x << endl;
   }
   system( "pause" );
   i = 1;
   for( x = 0.0; x != 1.0; x += 0.1 ) // should execute 10 times, right?
   {
      cout << "count " << setw(2) << i++ << ' ' << x << endl;
      if( x > 2.0 )
      {
          system( "pause" );
      }
   }
   return 0;
}

