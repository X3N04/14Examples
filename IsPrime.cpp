//
// IsPrime.cpp
//
// Keith Mehl
// Oct. 16, 2000
// CSCI-14 example program
// Illustrate Boolean value-returning function IsPrime()
// The function IsPrime() takes an integer and return true 
// if it is prime, else false.
// This program uses IsPrime() to see if a user entry is prime.
//
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime( int ); // function prototype
                     // or you can place the function body above main()

int main()
{
   int p;
   cout << "Enter candidate : " << flush;
   cin >> p;
   if( IsPrime( p ) ) // value from IsPrime() is value for if() test
   {
      cout << p << " is prime";
   }
   else
   {
      cout << p << " is NOT prime";
   }
   cout << endl;
   return 0;
}

// IsPrime() returns TRUE if its parameter n is prime, else FALSE
bool IsPrime( int n )   // function definition
{
   int lastDiv;
   if( n <= 2 ) // negative or 0 or 1 isn't prime; 2 is prime
   {
      return n > 1; // <= 1 false, 2 (max possible after if test) true
   }
   if( !( n % 2 ) )  // divisible by 2 = not prime
   {
      return false;
   }
   // otherwise loop from 3 through square root of number counting by 2
   lastDiv = (int)sqrt( (double)n );
   for( int i = 3; i <= lastDiv; i += 2 )
   {
      if( !( n % i ) )  // if any odd value divides number, not prime
      {
         return false;
      }
   }
   return true;  // if nothing divides number evenly, it's prime
}


