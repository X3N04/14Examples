//
// agerange.cpp
//
// Keith Mehl
// Sept. 19, 2000
//
// CSCI 14 example program demonstrating the cascaded if-else
// control structure, C++ string objects
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    float age;				// for entry of person's age as years w/fraction
    string name = "";	   // for person's name, a C++ string object
    cout << endl << "Enter name: " << flush;
    cin  >> name;	// read name. notice that only reads name up to a space!
    cin.ignore( 100, '\n' );  // "flush" input - ignore rest of input buffer
    cout << "Enter age: " << flush;
    cin  >> age;
    cout << '\n' << name << " is a"; // notice avoiding duplicate code.
    if( age < 1.0f )
    {
        cout << "n infant";	// 'a' + 'n' = "an", then, space, infant
    }
    else if( age < 3.0f )
    {
        cout << " toddler";	// no 'n', so "a toddler"
    }
    else if( age < 6.0f )
    {
        cout << " pre-school child";
    }
    else if( age < 13.0f )
    {
        cout << " pre-teenage child";
    }
    else if( age < 18.0f )
    {
        cout << " teenager";
    }
    else if( age < 21.0f )
    {
        cout << " young adult";
    }
    else if( age < 40.0f )
    {
        cout << "n adult";
    }
    else if( age < 55.0f )
    {
        cout << " middle aged person";
    }
    else if( age < 70.0f )
    {
        cout << " senior citizen";
    }
    else if( age < 100.0f )
    {
        cout << "n elderly citizen";
    }
    else
    {
        cout << " centenarian";
    } // end if( age )
    // age >= 100 is is a great achievement, so end line with '!' not '.'
    if( age >= 100.0f ) // note 2 ways to get to next line and flush output
    {
        cout << "!\n" << flush; // literal '\n' followed by flush
    }
    else
    {
        cout << '.' << endl;     // endl is equivalent to '\n', then flush
    } // end if( age )
    return 0;
}

