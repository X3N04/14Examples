//
// bubble.cpp
// Keith Mehl 10/26/2005
// CSCI-14 Example program
// Illustrate bubble sort algorithm
//

#include <iostream>
using namespace std;

void swap( int &a, int &b )
{
   int t = a;
   a = b;
   b = t;
   return;
}

void PrintIt( int a[], int n )
{
   for( int i = 0; i < n; i++ )
   {
      cout << a[i];
      if( i == n-1 ) {
         cout << endl;
      } else {
         cout << ' ' << flush;
      }
   }
   return;
}

int main()
{
   int i, a[6] = { 6, 4, 5, 2, 1, 3 };
   bool sorted = false;
   PrintIt( a, 6 );
   while( !sorted ) {
      sorted = true;
      for( i = 0; i < 5; i++ ) {
         if( a[i] > a[i+1] ) {
            sorted = false;
            swap( a[i], a[i+1] );
         }
      }
      PrintIt( a, 6 );
   }
   return 0;
}
