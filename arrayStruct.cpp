//
// arrayStruct.cpp
//
// Keith Mehl 11/30/04
// CSCI-14 example program
// Illustrate using an array of structs
//
#include <iostream>
using namespace std;
#define SUCCESS 0
#define FAILURE (!(SUCCESS))
#define MAX 100
struct STUDENT
{
   char WNum[10];    // W-number - 9 chars + 1 for NUL (KEY)
   char fName[MAX];  // first name - program assumes no spaces in names
   char lName[MAX];  // last name
   int age;
   float gpa;
};

// read one STUDENT from input stream by reference
// return success (0) if read, failure (non-0) if end-of-file
// the istream & parameter allows this to be called using either an 
// istream (cin) or an ifstream
int ReadPerson( istream &in, STUDENT &p )
{
   if( in >> p.WNum >> p.fName >> p.lName >> p.age >> p.gpa )
   {
      return SUCCESS;
   }
   return FAILURE;
}
// Print STUDENT to ostream out
void PrintPerson( ostream &out, STUDENT &p )
{
   out << "W-number  : " << p.WNum << "\nFirst Name: " << p.fName
       << "\nLast Name : " << p.lName << "\nAge       : " << p.age
       << "\nGPA       : " << p.gpa << endl;
   return;
}

int main( void )
{
   STUDENT people[MAX];
   int count = 0, i;
   // read the people into the array
   while( count < MAX && ReadPerson( cin, people[count] ) == SUCCESS )
   {
      count++;
   }
   cout << "We read " << count << " people" << endl;
   // print them back out
   for( i = 0; i < count; i++ )
   {
      PrintPerson( cout, people[i] );
      cout << "-------------------------------" << endl;
   }
   // find the middle person and print the GPA
   i = count / 2;
   cout << "For the middle person (at position " << i << "), "
        << people[i].fName << ", the GPA is "
        << people[i].gpa << endl;
   return 0;
}

