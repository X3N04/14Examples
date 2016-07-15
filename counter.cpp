//
// counter.cpp
//
// Keith Mehl
// 10/21/09
// CSCI-14 Example Program
// Count up or down, using only one loop for the counting
// Illustrate setting up initial condition, stop condition and
// and progress condition for a loop
//
#include <iostream>
using namespace std;

int main()
{
    int first, last, counter, end, step;
    cout << "Enter two numbers : " << flush;
    cin  >> first >> last;
    // set up loop conditions: start, stop, step value
    // start at first; stop when past last (going either direction)
    // step is either 1 or -1 depending on direction we're counting
    // this could be set up using an if-else(), but this is shorter
    step = first <= last ? 1 : -1;
    end  = first <= last ? last + 1 : last - 1;
    for( counter = first; counter != end; counter += step )
    {
        cout << counter << endl;
    }
    return 0;
}

