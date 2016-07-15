//
// doubleLoopTest.cpp
//
// Keith Mehl
// 11/17/09
// CSCI-14 example program
// illustrate why you don't trust == or != with floating point numbers
//

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstdlib>  // for system()

int main()
{
   double x;
   int i = 0;
   cout << "       ---------|---------|---------|---------|" << endl;
   // loop, count 0, 0.1, 0.2, ... until we hit 1.0, then stop.  What happens?
   for( x = 0.0; x != 1.0 && x < 2.0; x += 0.1 )
   {
      cout << "i = " << setw(2) << i++ << ' ' << x << endl;
   }
   system( "pause" );  // runs the DOS pause command - "Press any key..."
   cout << "       ---------|---------|---------|---------|" << endl;
   // show what is really going on with this
   i = 0;
   for( x = 0.0; x != 1.0 && x < 2.0; x += 0.1 )
   {
      cout << "i = " << setw(2) << i++ << ' '
           << setw(7) << setprecision(5)
           << showpoint << fixed << x << "\t "
           << setw(22) << setprecision(20)
           << showpoint << fixed << x << endl;
   }
   return 0;
}


