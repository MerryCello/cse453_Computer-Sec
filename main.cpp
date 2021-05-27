#include <iostream>
#include <string>
#include "pathDebunker.h"
#include "injection.h"

using namespace std;

/// What's being run macros
// #define JUST_TESTS
//#define LAB_WEEK5
#define LAB_WEEK6

/// COLORS
#define RESET  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGNA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"


void pathDebunker();
void injection();


int main() {
#ifdef LAB_WEEK5
   pathDebunker();
#endif

#ifdef LAB_WEEK6
   injection();
#endif
   return 0;
}


/*******************************************************************
 * WEEK 5 LAB
 * This week we will simulate a homograph attack attack and write the
 * code necessary to mitigate against it. This lab will be conducted
 * in our teams and will be submitted as a report.
 * *****************************************************************/
void pathDebunker() {
#ifndef JUST_TESTS
   string path1 = retrievePath();
   cout << "Again, ";
   string path2 = retrievePath();

   if (pathsAreHomographs(path1, path2)) {
      cout << endl << "Sorry, this program is homographophobic. Paths are homographs, ew!" << endl;
   } else {
      cout << "Hmmmm Path aren't homographs!" << endl;
   }
#endif

   // Tests
   runTests();
}


/**
 * WEEK 6 LAB
 */
void injection() {
   cout << "\ninjection\n";
}
