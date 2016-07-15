//
// roman.cpp
//
// Keith Mehl 9/2/2000
// CSCI 14 example program
// 
// This program converts a number between 1 and 5000, inclusive, that
// is entered by the user in Arabic form into its equivalent Roman
// numeral form.
// The number is converted into "additive" Roman form, e.g., 4 is IIII
// It loops prompting for numbers and converting them until the user
// enters 0.
// 
// Algorithm to convert number in pseudocode:
// If the number (n) is out of range
//    handle error or quit program
// else
//    while( n >= 1000 ) // loop, since can have more than 1 M in 5000
//       print M
//       n -= 1000 (M)
//    end while
//    if( n >= 500 )     // if, since can have only 1 D in under 1000
//       print D
//       n -= 500  (D)
//    endif
//    ... continue in a similar fashion to print out
//        the C (100), L (50), X (10), V (5), and I (1) characters
//  end if
//

#include <iostream>
using namespace std;

const int M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1;

int main()
{
   int arabic;   // holds user entry
   cout << "This program converts Arabic numbers from 1 to 5000 "
        << "to Roman numbers.\nType 0 at the prompt to stop." << endl;

   do // infinite do-while loop with break; to get out
   {
      cout << "Number? " << flush;
      cin >> arabic;
      if( arabic > 5000 )  // input too big?
      {
         cout << "The number must be between 1 and 5000\n";
      }
      else if( arabic <= 0 ) // sentinel to get out of loop
      {
         break;   // break out of infinite do-while loop
      }      
      else  // number must now be between 1 and 5000 inclusive     
      {     // so there is no need to test it again
         cout << '\n' << arabic << "\t<------>\t" << flush;
         while( arabic >= M )   // M is 1000
         {
            cout << 'M';
            arabic -= M;
         } // end while
         if( arabic >= D )      // D is 500
         {
            cout << 'D';
            arabic -= D;
         } // end if
         while( arabic >= C )   // C is 100
         {
            cout << 'C';
            arabic -= C;
         } // end while
         if( arabic >= L )      // L is 50
         {
            cout << 'L';
            arabic -= L;
         } // end if
         while( arabic >= X )   // X is 10
         {
            cout << 'X';
            arabic -= X;
         } // end while
         if( arabic >= V )      // V is 5
         {
            cout << 'V';
            arabic -= V;
         } // end if
         while( arabic >= I )   // and I is 1
         {
            cout << 'I';
            arabic -= I;
         } // end while
      } // end if( arabic )
      cout << endl;
   } while( true );
   return 0;
}

