//
// longadd.cpp
//
// Keith Mehl
// 5/5/12
// CSCI-14 Assignment program
// add long integers with digits held in arrays
//
#include <iostream>
#include <fstream>
using namespace std;
// table sizes with room for overflow
const int MAX = 25;

// find the end of the C-string, or you can use cstring's strlen()
int findEnd( char s[] )
{
    int i;
    for ( i = 0; s[i]; i++ ); // empty for() loop to count
    return i;
}

// reverse the C-string source into C-string target
void loadOp( char source[], char target[] )
{
    int i, j;
    i = findEnd( source ) - 1;
    j = 0;
    while ( i >= 0 )
    {
        target[j++] = source[i--];
    }
    target[j] = '\0'; // terminating NUL (just in case)
    return;
}
// clear a buffer of fixed size MAX to all NUL characters
// or you can use cstring memset() function: memset( a, '\0', MAX );
void clear( char a[] )
{
    for ( int i = 0; i < MAX; i++ )
    {
        a[i] = '\0';
    }
}

// do the addition
void add( char op1[], char op2[], char sum[] )
{
    int i, left, right, result, digit, carry = 0; // carry starts 0 (carry in)
    clear( sum );
    i = 0;
    // while we have either a digit in either operand or a carry (out)
    while ( op1[i] || op2[i] || carry )
    {
        // can use cctype's isdigit() to test '0'...'9'
        // get digit value (convert from ASCII char value)
        // if off end of number, use 0 for digit value
        left   = ( op1[i] >= '0' && op1[i] <= '9' ) ? op1[i] - '0' : 0;
        right  = ( op2[i] >= '0' && op2[i] <= '9' ) ? op2[i] - '0' : 0;
        result = left + right + carry; // add
        digit  = result % 10;  // strip rightmost digit for sum
        carry  = result / 10;  // strip leftmost digit (if there) for carry
        sum[i] = (char)(digit + '0');  // convert back to a char
        i++;                   // on to next digit
    }
    return;
}
// print the formatted output to the output file
// or, just use setw() to set field sizes and cut this by more than half...
void print( ostream & out, char addend[], char augend[], char sum[] )
{
    int i, j, k, m, sp, x;
    char buf1[MAX] = "", buf2[MAX] = "", buf3[MAX] = "";
    loadOp( addend, buf1 );  // buffers are reversed to add, reverse again to print
    loadOp( augend, buf2 );
    loadOp( sum, buf3 );
    i = findEnd( buf1 );     // find ends of buffers for alignment logic
    j = findEnd( buf2 );
    k = findEnd( buf3 );
    m = (i > j ? i : j) + 3; // length of longest operand + room for " + "
    sp = m - i;              // how many spaces to print here
    for ( x = 0; x < sp; x++ )
    {
        out << ' ';
    }
    out << buf1 << endl << " + ";  // " + " is 2nd line addition sign
    sp = m - j;              // need 3 fewer spaces because of " + "
    for ( x = 0; x < sp - 3; x++ )
    {
        out << ' ';
    }
    out << buf2 << endl << ' '; // skip a ' ' before "---" addition bar
    for ( x = 1; x < m; x++ )   // print the bar
    {
        out << '-';
    }
    // and the sum, may or may not need an extra ' ' before it, & skip a line
    out << (k > m - 3 ? "\n  " : "\n   ") << buf3 << endl << endl;
    return;
}
// open files, process, shut down
int main()
{
    char addend[MAX] = "", augend[MAX] = "", sum[MAX] = "", inbuf[MAX] = "";
    ifstream fin( "longNumbers.txt" );  // hard coded file names
    ofstream fout( "longResults.txt" );
    if ( !fin || !fout )
    {
        cout << "File open error" << endl;
        return -1;
    }
    fin >> inbuf;          // priming read
    while ( inbuf[0] >= '0' && inbuf[0] <= '9' )  // or use isdigit(inbuf[0])
    {
        loadOp( inbuf, addend );
        fin >> inbuf;
        loadOp( inbuf, augend );
        add( addend, augend, sum );
        print( fout, addend, augend, sum );
        clear( addend );   // clear operands for next pass
        clear( augend );
        clear( sum );
        fin >> inbuf;      // continuing read
    }
    fin.close();
    fout.close();
    return 0;
}

