//
// ripple.cpp
// Keith Mehl
// 11/2/05
//
// CSCI-14 Example Program
// Illustrate ripple sort
//

#include <iostream>
using std::cout; // you can specify individual labels in using statements
using std::flush;
using std::endl;

void swap( int &a, int &b )
{
   int t = a;
   a = b;
   b = t;
   return;
}

void printIt( int a[], int n )
{
   for( int i = 0; i < n; i++ )
   {
      cout << a[i];
      if( i == n-1 )
      {
         cout << endl;
      } 
      else 
      {
         cout << ' ' << flush;
      }
   }
   return;
}

int main()
{
   int i, j, a[6] = { 4,2,6,3,1,5 };
   bool sorted = false;
   printIt( a, 6 );
   for( i = 0; i < 5; i++ ) 
   {
      for( j = i+1; j < 6; j++ ) 
      {
         if( a[i] > a[j] ) 
         {
            swap( a[i], a[j] );
         }
      }
      printIt( a, 6 );
   }
   return 0;
}

