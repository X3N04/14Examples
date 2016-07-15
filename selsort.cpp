//
// selsort.cpp
//
// Keith Mehl
// 4/17/1012
// CSCI-14 example program
// Illustrate selection sort
//

#include <iostream>
using namespace std;

// very simple printing function
void print( int a[], int n )
{
   for( int i = 0; i < n; i++ )
   {
      cout << a[i];
      if( i < n-1 )
      {
         cout << ' ' << flush;
      }
   }
   cout << endl;
   return;
}

void swap( int &a, int &b )
{
   int t = a;
   a = b;
   b = t;
   return;
}

// find the smallest element in the n-element array a starting at index i
int findSmall( int a[], int i, int n )
{
   int small = i, j;
   for( j = i + 1; j < n; j++ )
   {
      if( a[small] > a[j] )
      {
         small = j;
      }
   }
   return small;
}

void selSort( int a[], int n )
{
   for( int i = 0; i < n-1; i++ )
   {
      swap( a[i], a[findSmall( a, i, n )] );
      print( a, n );
   }
   return;
}

int main()
{
   int a[10] = { 2, 1, 5, 3, 9, 0, 8, 7, 6, 4 };
   print( a, 10 );
   selSort( a, 10 );
   print( a, 10 );
   return 0;
}


