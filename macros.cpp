//
// macros.cpp
//
// Keith Mehl
// 11/17/09
// illustrate some simple C++ macros
//

#include <iostream>
using namespace std;

// macros are "over-parenthesized" because of precedence problems
// if passing in complex expressions, e.g., MAX(a+b,c-d)
// functions like min(a,b) or max(a,b) are type-specific
// macros allow type-independent evaluation of expressions,
// but the code is expanded every time it is compiled, instead of
// being defined once and executed from several places like functions

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ABS(a)   (((a)>=0)?(a):(-(a)))

int main()
{
   int a, b, c;
   float x, y, z;
   
   cout << "Enter two ints : " << flush;
   cin  >> a >> b;
   cout << "Enter two floats : " << flush;
   cin  >> x >> y;
   
   c = MAX(a,b);
   z = MAX(x,y);
   
   cout << "MAX of " << a << " and " << b << " is " << c << endl;
   cout << "MAX of " << x << " and " << y << " is " << z << endl;

   c = MIN(a,b);
   z = MIN(x,y);
   
   cout << "MIN of " << a << " and " << b << " is " << c << endl;
   cout << "MIN of " << x << " and " << y << " is " << z << endl;
   
   c = ABS(a);
   z = ABS(x);
   
   cout << "ABS of " << a << " is " << c << endl;
   cout << "ABS of " << x << " is " << z << endl;
   return 0;
}


