/*******************************************************************
 * This week we will simulate a homograph attack attack and write the
 * code necessary to mitigate against it. This lab will be conducted
 * in our teams and will be submitted as a report.
 * *****************************************************************/
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include "pathDebunker.h"

using namespace std;


/**
 * Prompts user for a path
 * @return the path
 */
string retrievePath() {
   string path;
   cout << "Specify thy path: ";
   do {
      cin >> path;
   } while (cin.fail());

   return path;
}


/** OTHER INTERPRETATION/SUGGESTION
 * Converts the input path into a string omitting "/" and "."  or ".." characters and compares it to an absolute path formatted the same way
 * e.g., "./../cse453/./homework/file.txt" becomes "cse453homeworkfiletxt"
 * if absolute path (the forbidden path) is "./cse453/myFiles/homework/secret/file.txt" then it becomes "cse453myFileshomeworksecretfiletxt"
 * comparing the two, we can then see that they are not the same
 */
string canonizePath(string & path) {
   string canonString;

   string currentDirectory;
   // step 1: split the path at the '/'and store in List
   list<string> splitPath(split(path, '/'));
   // step 2: iterate through the path and track the current directory (maybe with a recursive function?)
   // step 3: off of step 2, build the simplified path
   list<string> simplifiedPath = simplifyPath(splitPath.begin(), splitPath);
   // step 4: convert List back to string and return it
   for (auto it = simplifiedPath.begin();
        it != simplifiedPath.end();
        it++) {
      canonString += *it;
      if (it != simplifiedPath.end())
         canonString += "/";
   }
   // cout << canonString << endl;

   return canonString;
}


list<string> simplifyPath(list<string>::iterator currentDir,
                          list<string> & inputPath) {
   list<string> simplifiedPath;

   inputPath.remove(".");

   for (auto it = inputPath.begin(); it != inputPath.end(); it++) {
      if (*it == "~" || *it == "home") {
         simplifiedPath.push_back("home");
      }
      else if (*it == "..") {
         // delete the previous directory in the path
         if (simplifiedPath.size() >= 1 && simplifiedPath.end() != ++simplifiedPath.begin()){
            inputPath.erase(--simplifiedPath.end());
         }
         // Note: don't push_back the '..'
      }
      else {
         simplifiedPath.push_back(*it);
      }
   }

   return simplifiedPath;
}


/**
 * Splits a string by the splitter and stores the fragments into a list
 * @param str
 * @param splitter
 * @return split string
 */
list<string> split(string str, char splitter) {
   list<string> splitText;
   replace(str.begin(), str.end(), splitter, ' ');

   stringstream  ss(str);
   string temp;
   while (ss >> temp) {
      splitText.push_back(temp);
   }

   return splitText;
}


/**
 * Are paths homographs?
 * The paths are homographs if they are different, but point to the same thing.
 * @param path1
 * @param path2
 * @return
 */
bool pathsAreHomographs(string path1, string path2) {
   bool inputsAreDifferent = path1 != path2;
   if (!inputsAreDifferent) {
      return false;
   }

   string canonPath1 = canonizePath(path1);
   string canonPath2 = canonizePath(path2);

   bool pathsAreEqual = canonPath1 == canonPath2;

   return pathsAreEqual;
}


/*******************************************************************
 * TESTS
 *******************************************************************/
enum TestStatuses {
   TODO = 0,
   FAILED = 1,
   PASSED = 2
};

struct Test {
   string name;
   bool (*run)();
   TestStatuses status = TODO;
};

void runTests() {
   cout << "\nRunning tests on \"pathsAreHomographs(string, string)\"...\n";
   // Add tests here and increment int below
   int numberOfTests = 6;
   Test tests[] = {
      {
        "Homographs Test 1",
        test1,
      },
      {
        "Homographs Test 2",
        test2,
      },
      {
        "Homographs Test 3",
        test3,
      },
      {
        "Non Homographs Test 4",
        test4,
      },
      {
        "Non Homographs Test 5",
        test5,
      },
      {
        "Non Homographs Test 6",
        test6,
      }
   };

   int testsPassedCount = 0;
   for (int i = 0; i < numberOfTests; i++) {
      cout << "Running \"" << tests[i].name << "\"...\n";
      bool testPassed = tests[i].run();
      if (testPassed) {
         cout << "\t..." << "PASSED\n\n";
         tests[i].status = PASSED;
         testsPassedCount++;
      } else {
         cout << "\t...FAILED\n\n";
         tests[i].status = FAILED;
      }
   }

   cout << "==========================================================================\n"
        << testsPassedCount << "/" << numberOfTests << " tests passed\n";
}


/**
 * Homographs Test 1
 * @return
 */
bool test1() {
   // Setup
   string actualPath1 =  "/home/cs453/week05/test.txt";
   string path1 = "~/cs453/./week05/././test.txt";
   
   string actualPath2 =  "/home/cs453/week05/test.txt";
   string path2 = "home/./cs453/week05/test.txt";

   // Return a test report
   detailedTestCaseReport(actualPath1, path1, actualPath2, path2);

   // Test & Verify
   return pathsAreHomographs(path1, path2);
}


/**
 * Homographs Test 2
 * @return
 */
bool test2() {
   // Setup
   string actualPath1 = "/home/cs453/week05/week05/test.txt";
   string path1 = "~/cs453/week05/./week05/./././test.txt";
   
   string actualPath2 = "/home/cs453/week05/week05/test.txt";
   string path2 = "home/./cs453/../cs453/week05/./week05/./test.txt";

   // Return a test report
   detailedTestCaseReport(actualPath1, path1, actualPath2, path2);

   // Test & Verify
   return pathsAreHomographs(path1, path2);
}


/**
 * Homographs Test 3
 * @return
 */
bool test3() {
   // Setup
   string actualPath1 = "/home/week05/test.txt";
   string path1 = "home/../week05/test.txt";
   string actualPath2 = "/home/week05/test.txt";
   string path2 = "home/../week05/../week05/../week05/test.txt";

   // Return a test report
   detailedTestCaseReport(actualPath1, path1, actualPath2, path2);

   // Test & Verify
   return pathsAreHomographs(path1, path2);
}


/**
 * Non Homographs Test 4
 * @return
 */
bool test4() {
   // Setup
   string actualPath1 = "/home/cs453/week05/test.txt";
   string path1 = "~/./cs453/./week05/./././././test.txt";
   
   string actualPath2 = "/home/week05/test.txt";
   string path2 = "~/./cs453/../week05/././test.txt";

   // Return a test report
   detailedTestCaseReport(actualPath1, path1, actualPath2, path2);

   // Test & Verify
   return !pathsAreHomographs(path1, path2);
}


/**
 * Non Homographs Test 5
 * @return
 */
bool test5() {
   // Setup
   string actualPath1 = "/home/week04/test.txt";
   string path1 = "~/../week04/test.txt";
   
   string actualPath2 = "/home/week05/test.txt";
   string path2 = "~/../week05/test.txt";

   // Return a test report
   detailedTestCaseReport(actualPath1, path1, actualPath2, path2);

   // Test & Verify
   return !(pathsAreHomographs(path1, path2));
}


/**
 * Non Homographs Test 6
 * @return
 */
bool test6() {
   // Setup
   string actualPath1 = "/home/cs453/week05/test.txt";
   string path1 = "/home/../cs453/./week05/.././week05/././test.txt";

   string actualPath2 = "/home/cs453/test.txt";
   string path2 = "~/.././cs453/../cs453/week05/.././test.txt";

   // Return a test report
   detailedTestCaseReport(actualPath1, path1, actualPath2, path2);

   // Test & Verify
   return !pathsAreHomographs(path1, path2);
}



/**
 * Display a detailed test case report 
 */
void detailedTestCaseReport(string actualPath1, string inputPath1,
                            string actualPath2, string inputPath2) {
   cout << "\t1. \"Actual path\" >>> \"input path\":\n"
        << "\t   \"" << actualPath1 << "\" >>> \"" << inputPath1 << "\"" << endl;
   
   cout << "\t2. \"Actual path\" >>> \"input path\":\n"
        << "\t   \"" << actualPath2 << "\" >>> \"" << inputPath2 << "\"" << endl;
}
