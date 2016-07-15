//
// insSort.cpp
//
// Keith Mehl
// 4/17/12
// CSCI-14 example program
// Illustrate insertion sort
//

#include <iostream>
using namespace std;

void printIt( int a[], int n )
{
    cout << a[0];
    for( int i = 1; i < n; i++ )
    {
        cout << ' ' << a[i];
    }
    cout << endl;
}

void insSort( int a[], int n )
{
    int i, j, t;
    // printIt() is just to show progress at each pass
    printIt( a, n );
    // for each element after the first one
    for( i = 1; i < n; i++ )
    {
        // save the element off
        t = a[i];
        // for each element to its left, or we find one that's smaller
        for( j = i-1; j >= 0 && a[j] > t; j-- )
        {
            // shift the element to the right to make a hole for the saved one
            a[j+1] = a[j];
        }
        // put the saved element into the hole
        a[j+1] = t;
        printIt( a, n );  // progress report...
    }
    return;
}

int main()
{   
    int a[8] = { 8, 2, 5, 6, 4, 7, 3, 1 };
    insSort( a, 8 );
    return 0;
}

