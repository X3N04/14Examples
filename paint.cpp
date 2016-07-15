//
// paint.cpp
//
// Keith Mehl
// 8/30/04
// CSCI-14 Example program
// Figure out how much paint we need to paint a wall
//
#include <iostream>  // get access to input/output streams library
using namespace std; // iostream labels are in "std" namespace
      // named constant to give mnemonic name to "magic number"
const float SqFtPerGal = 350.0f;
      // the function main() is always the entry point of the application
int main()
{
   float length, width, area, paint;  // to hold user values and results
   // prompt user for length and width of wall
   cout << "Enter length of wall : " << flush;
   cin  >> length;
   cout << "Enter width of wall : " << flush;
   cin  >> width;
   // calculate area and amount of paint needed
   area  = length * width;
   paint = area / SqFtPerGal;
   // output results with reasonable text
   cout << "You need " << paint << " gallons of paint to cover "
        << area << " square feet of wall." << endl;
   // program stops executing when it returns from main(), 0 means O.K.
   return  0;
}
