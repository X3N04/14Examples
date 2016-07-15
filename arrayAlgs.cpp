//
// arrayAlgs.cpp
//
// Keith Mehl
// 11/16/09
// Illustrate some algorithms on arrays used for lists
// particularly insertions in order and deletions
//

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;  // 100 array elements

// print count elements of array a with reasonable width
void PrintIt( int a[], int count )
{
   for( int i = 0; i < count; i++ )
   {
      cout << setw(4) << a[i];
   }
   cout << endl;
   return;   
}

int main()
{
   int a[MAX] = { 0 }, count = 0, n, i, j;
   // first, built an ordered list of elements
   cout << "Enter elements to insert into array, <= 0 to stop : " << flush;
   cin  >> n;
   // until we either run out of room or get a stop sentinel
   while( count < MAX && n > 0 )
   {
      // insert n into array a in sorted order
      // this insertion algorithm is not quite the fastest possible.  why?
      i = 0;  // scan from left looking for place to insert
      // we can either run off the end of the list or find a spot inside list
      // why do I check i < count first here, not a[i] < n first?
      while( i < count && a[i] < n ) 
      {
         i++;
      }
      // if at the end, just add
      if( i >= count )
      {
         a[count++] = n;
      }
      else  // otherwise, shift over everything to the right to make a hole
      {
         for( j = count; j > i; j-- )
         {
            a[j] = a[j-1];
         }
         a[j] = n;
         count++;
      }
      PrintIt( a, count );
      if( count < MAX )  // only read next number if there is room
      {
         cin >> n;
      }
   }
   // now to remove elements by key, if duplicate key remove first one in list
   cout << "Enter elements to remove from array, <= 0 to stop : " << flush;
   cin  >> n;
   // we can run out of elements in the array or get the stop sentinel
   while( count > 0 && n > 0 )
   {
      // find element in the array
      // stopping if we go past it (since array is sorted)
      // this is logically equivalent to while loop above, scanning for n
      for( i = 0; i < count && a[i] < n; i++ ); // note the empty loop body!
      
      if( i < count && a[i] == n ) // found it?
      {
         for( j = i; j < count; j++ )
         {
            a[j] = a[j+1];
         }
         count--;
      }
      else 
      {
         cout << n << " is not in the list." << endl;
      }
      PrintIt( a, count );
      if( count > 0 )  // don't bother getting a key if the list is empty
      {
         cin >> n;
      }
   }
   return 0;
}

