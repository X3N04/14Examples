//
// bitops.cpp
// Keith Mehl 12/9/2004
// CSCI-14 Example program
// Illustrate bitwise shift operator >> and hexadecimal number format
//
#include <cstdio>   // for sprintf()
#include <iostream>
using namespace std;

int main( void )
{
    // set a and b, x and y to maximum possible values, both
    // signed and unsigned (all bits but sign bit on,
    // or all bits on, period).  Machine-specific values are in
    // the <climits> header, e.g., LONG_MAX, ULONG_MAX, etc.  
    // Some machines represent negative numbers using a different format.
    long a = 0x7fffffff, b = 0xffffffff; // 
    unsigned long x = 0x7fffffff, y = 0xffffffff;
    char buf[1000] = ""; // work buffer for sprintf()
    // sprintf() takes a character buffer (buf),
    // a format string (here "a = 0x%lx\t%10ld\n"), and
    // a variable number of arguments to match the format
    // specifiers (start with %) in the format string.  It returns the
    // number of arguments successfully formatted (here ignored)
    // the %lx format specifier means "long int in hexadecimal"
    // %10ld means "long int in 10 bytes in decimal" %u means "unsigned int"
    // You MUST match the variable arguments to the format
    // specifiers in both type and sequence -- the compiler DOES
    // NOT check this for you!
    sprintf( buf, "a = 0x%lx\t%10ld\n", a, a );
    cout << buf;
    sprintf( buf, "b = 0x%lx\t%10ld\n", b, b );
    cout << buf;
    sprintf( buf, "x = 0x%lx\t%10u\n", x, x );
    cout << buf;
    sprintf( buf, "y = 0x%lx\t%10u\n", y, y );
    cout << buf;
    while( a > 0 )
    {
        cout << "*-------------------------*\n";
        a >>= 1;   // shift a and b right by 1 bit (signed)
        sprintf( buf, "a = 0x%08lx\t%10ld\n", a, a );
        cout << buf;
        b >>= 1;
        sprintf( buf, "b = 0x%08lx\t%10ld\n", b, b );
        cout << buf;
        x >>= 1;   // shift x and y right by 1 bit (unsigned)
        sprintf( buf, "x = 0x%08lx\t%10ld\n", x, x );
        cout << buf;
        y >>= 1;
        sprintf( buf, "y = 0x%08lx\t%10ld\n", y, y );
        cout << buf;
    }
    cout << flush;
    return 0;
}

