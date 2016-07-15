//
// fileIO.cpp
// Keith Mehl
// 11/01/07
// CSCI-14 example program
// Illustrate very simple direct file I/O with fstreams
//
#include <iostream>
#include <fstream> // for ifstream and ofstream
#include <cstdlib> // for system()
using namespace std;

int main()
{
   // a work area to hold a line of text (array of char)
   char buffer[100] = "";
   char ch; // to hold single characters one at a time

   // Use a default file name for output file.  At
   // the time main loads, the file "fileIO.txt" will
   // be associated with the output file stream (file handle or file object)
   // fout, which will then work exactly like cout for output.
   ofstream fout( "fileIO.txt" );

   // Don't associate a file with the file handle fin yet.
   // The association is made at the fin.open() call later.
   // Either way to create/open the file handle will
   // work with either input or output files.  You don't
   // have to follow this example exactly...
   ifstream fin;

   // did the file open fail?  You cannot assume it worked!
   if( !fout )
   {
      cout << "Output file open failed\n";
      return -1;  // if the file fails to open, you cannot process, so quit!
   }

   // Write a few lines of text to the output file
   fout << "The quick brown fox jumps over a lazy dog.\n";
   fout << "Now is the time for all good men "
        << "to come to the aid of their party." << endl;

   // Break the association between the file handle and the file.
   // This also assures the data is written to the disk (could be buffered).
   fout.close();

   // Show user that the file was created correctly.  This is not needed!
   // I just did it here to show that the write ti the file worked.
   // system() runs a command as though it was run from the O/S
   // command line. In DOS type dumps the contents of the file to the screen.
   // system() returns the exit status (the return value from main())
   // of the executed program.  By convention 0 is SUCCESS, non-0
   // is FAILURE.  We don't care about that value here.
   system( "type fileIO.txt" ); // This assumes DOS or WINDOWS CMD shell
   cout << "~~~~~~" << endl;

   // Now read the data back into the program from the disk file.
   // fin.open() associates the file "fileIO.txt" with the handle fin
   fin.open( "fileIO.txt" );

   // Check for open failure.  You cannot assume it worked!
   if( !fin )
   {
      cout << "Input file open failed\n";
      return -2;
   }

   // Read a line of text from input.  This getline() function (method)
   // will put input into buffer, maximum of 99 characters, stopping at '\n'
   fin.getline( buffer, 99, '\n' );
   cout << "We read this line from input:\n" << buffer << endl;

   // loop reading one character at a time until we see a space
   // mark start/end of the sequence with <> just to show whitespace
   cout << "get()-ing one character at a time until we see a ' ':\n<";
   do
   {
      fin.get( ch );  // get one character, whatever it is, from input
      cout << ch;
   } while( fin && ch != ' ' && ch != '\n' ); // stop at failure or sentinel
   cout << '>' << endl;

   // now extract words from the file until end-of-file
   cout << "Extracting one word at a time:" << endl;
   fin  >> buffer;    // priming read
   while( !fin.eof() )
   {
      // the < and > are just to delimit the word when printing...
      cout << "<" << buffer << ">" << endl;
      fin  >> buffer;
   }
   cout << endl;
   fin.close();
   return 0;
}

