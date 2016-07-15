//
// bitOpTest.cpp
//
// Keith Mehl
// 12/5/2011
// CSCI-14 Example program
// Illustrate bitwise operators
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int a = 0x01234567;
   int b = 0x89ABCDEF;
   int c;
   
   cout << "a = " << a << ", b = " << b << endl;
   cout << hex << "a =  " << a << ", b = " << b << endl;

   c = a & b;
   cout << "a & b = " << c << endl;
   c = a | b;
   cout << "a | b = " << c << endl;
   c = a ^ b;
   cout << "a ^ b = " << c << endl;
   c = ~b;
   cout << "~b = " << c << endl;
   
   return 0;
}

