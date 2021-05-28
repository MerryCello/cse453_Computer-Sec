#include <iostream>
#include <string>
#include <regex>

using namespace std;
typedef string (*GenQueryFunction)(string, string);

struct Credentials;
struct TestSet;
string genQuery(string, string);
string genQueryWeak(string, string);
string genQueryStrong(string, string);
void runTestCases(char);
void runTests(TestSet&);
void testValid(TestSet&);
void testTautology(TestSet&);
void testUnion(TestSet&);
void testAddState(TestSet&);
void testComment(TestSet&);


int main() {
   char mitigationType = 'r';

   cout << "Options:\n"
        << "   r => Run tests on regular genQuery\n"
        << "   w => Run tests on weak    genQuery\n"
        << "   s => Run tests on strong  genQuery\n"
        << "   a => Run tests on on all  genQueries\n\n";
   bool wrongInputOption;
   do {
      cout << "> ";
      cin >> mitigationType;
      wrongInputOption = cin.fail() || (
                           mitigationType != 'r'
                           && mitigationType != 'w'
                           && mitigationType != 's'
                           && mitigationType != 'a'
                        );
      if (wrongInputOption) {
         cout << "Wrong option.\n";
      }
   } while(wrongInputOption);
   cout << endl;

   //Depending on type return proper test case
   runTestCases(mitigationType);

   return 0;
}

string genQuery(string username, string password) {
    return "SELECT authenticate FROM passwordList WHERE name='" + username + "' and passwd='" + password + "';";
}

/*******************************************************************
 * Weak Filter:
 *      - Strip the username and password of <, >, &, ;, "", etc.
 *******************************************************************/
string genQueryWeak(string username, string password) {
   // SELECT authenticate FROM passwordList WHERE name='$Username' and passwd='$Password'
   string sqlQuery = "SELECT authenticate FROM passwordList WHERE name='" + username + "' and passwd='" + password + "';";
   string cleanQuery;
   for (char & c : sqlQuery) {
      char invalidChars[] = {'<', '>', '&', ';', '"', '-'};
      for (char invalidChar : invalidChars) {
         if (c == invalidChar) {
            cleanQuery += "";
            break;
         } else {
            cleanQuery += c;
            break;
         }
      }
   }

   return cleanQuery;
}

/*******************************************************************
 * Strong Filter:
 *       - Username: Allow only letters, numbers, ., and _
 *       - Password: Allow only letters, numbers, and special characters (!@#$%^&*._)
 *******************************************************************/
string genQueryStrong(string username, string password) {
   // Don't know for sure if solution works, but it should
   string cleanUsername;
   string cleanPassword;
   for (char c : username) {
      if (isalnum(c) || c == '.' || c == '_'))
         cleanUsername += c;
   }
   for (char c : password) {
      string s(1, c);
      if (isalnum(c) || regex_match(s, regex("[\\w!@#$%^&*_.]")))
         cleanPassword += c;
   }

   string sqlQuery = "SELECT authenticate FROM passwordList WHERE name='" + cleanUsername + "' and passwd='" + cleanPassword + "';";
   return sqlQuery;
}


/*******************************************************************
 * TESTS
 *******************************************************************/

struct Credentials {
   Credentials(string username, string password) : username(std::move(username)), password(std::move(password)) {}

   string username;
   string password;
};
enum TestStatuses {
   TODO = 0,
   FAILED = 1,
   PASSED = 2
};
struct TestCase {
   Credentials input;
   string expectedOutput;
   string errorMessage;
   TestStatuses status = TODO;
};
struct TestSet {
   string title;
   string name;
   GenQueryFunction functionTested = nullptr;
   int testsNumber = 0;
   int testsPassedCount = 0;
   TestCase *testCases = nullptr;
};


void runTestCases(char mitigationType) {
   TestSet testSets[3];
   string setGroupTitle;
   switch (mitigationType) {
      /// Regular
      case 'r': {
         testSets[0].title = "genQuery()";
         testSets[0].functionTested = genQuery;
         break;
      }
      /// Weak
      case 'w': {
         testSets[0].title = "genQueryWeak()";
         testSets[0].functionTested = genQueryWeak;
         break;
      }
      /// Strong
      case 's': {
         testSets[0].title = "genQueryStrong()";
         testSets[0].functionTested = genQueryStrong;
         break;
      }
      /// All
      case 'a': {
         setGroupTitle = "RUNNING TESTS ON ALL GEN_QUERIES...";
         testSets[0].title = "genQuery()";
         testSets[0].functionTested = genQuery;
         testSets[1].title = "genQueryWeak()";
         testSets[1].functionTested = genQueryWeak;
         testSets[2].title = "genQueryStrong()";
         testSets[2].functionTested = genQueryStrong;
         break;
      }

      default:
         throw "Uh oh, wrong option...";
   }

   /// Run all tests
   if (mitigationType == 'a') {
      cout << setGroupTitle << endl;

      int testsPassedCount = 0;
      for (TestSet & testSet : testSets) {
         cout << "   Running set \"" << testSet.title << "\"...\n";
         testValid(testSet);
         testTautology(testSet);
         testUnion(testSet);
         testAddState(testSet);
         testComment(testSet);
         testsPassedCount += testSet.testsPassedCount;
         cout << "   **************************************************************************\n"
              << "   *  " << testSet.testsPassedCount << "/25 tests passed for \"" << testSet.title << "\"\n"
              << "   **************************************************************************\n\n";
      }
      cout << "==========================================================================\n"
           << "|| TOTAL: " << testsPassedCount << "/" << 3*25 << " tests passed\n"
           << "==========================================================================\n\n";
   }
   /// Run the specified test
   else {
      cout << "Running set \"" << testSets[0].title << "\"...\n";
      testValid(testSets[0]);
      testTautology(testSets[0]);
      testUnion(testSets[0]);
      testAddState(testSets[0]);
      testComment(testSets[0]);

      cout << "**************************************************************************\n"
           << "*  " << testSets[0].testsPassedCount << "/25 tests passed for \"" << testSets[0].title << "\"\n"
           << "**************************************************************************\n\n";
   }
}

void testValid(TestSet& testSet) {
   /// setup
   testSet.name = "Valid input";
   testSet.testsNumber = 5;
   string errorMessage = "Query not properly build with VALID input";
   // TODO: setup tests
   testSet.testCases = new TestCase[5] {
      // { username, password, expected output }
           { Credentials("Jane Doe", "7593156"), "", errorMessage }, // Jared
           { Credentials("w4shingt0nx4vier", "509@pp1e"), "", errorMessage }, // Paul
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage }
   };

   /// test & validate
   runTests(testSet);

   delete testSet.testCases;
   testSet.testCases = nullptr;
}


void testTautology(TestSet& testSet) {
   /// setup
   testSet.name = "Tautology exploitation";
   testSet.testsNumber = 5;
   string errorMessage = "Query failed due to a BOOLEAN attack";
   // TODO: setup tests
   testSet.testCases = new TestCase[5] {
           // { username, password, expected output }
           { Credentials("Jane Doe", "'fake_password' OR 'x' = 'x'"), "", errorMessage }, // Jared
           { Credentials("w4shingt0nx4vier", ""), "", errorMessage }, // Paul
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage }
   };

   /// test & validate
   runTests(testSet);

   delete testSet.testCases;
   testSet.testCases = nullptr;
}


void testUnion(TestSet& testSet) {
   /// setup
   testSet.name = "Union exploitation";
   testSet.testsNumber = 5;
   string errorMessage = "Query was altered to execute a UNION";
   // TODO: setup tests
   testSet.testCases = new TestCase[5] {
           // { username, password, expected output }
           { Credentials("Jane Doe", "testing' UNION INSERT INTO  passwordList VALUES('Jane Doe', 'my_password')"), "", errorMessage }, //Jared
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage }
   };

   /// test & validate
   runTests(testSet);

   delete testSet.testCases;
   testSet.testCases = nullptr;
}


void testAddState(TestSet& testSet) {
   /// setup
   testSet.name = "Add State exploitation";
   testSet.testsNumber = 5;
   string errorMessage = "A state was added to the query";
   // TODO: setup tests
   testSet.testCases = new TestCase[5] {
           // { username, password, expected output }
           { Credentials("Jane Doe", "0; SELECT password FROM passwordList"), "", errorMessage }, // Jared
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage }
   };

   /// test & validate
   runTests(testSet);

   delete testSet.testCases;
   testSet.testCases = nullptr;
}


void testComment(TestSet& testSet) {
   /// setup
   testSet.name = "Comment exploitation";
   testSet.testsNumber = 5;
   string errorMessage = "Comments altered how the query should have run";
   // TODO: setup tests
   testSet.testCases = new TestCase[5] {
           // { username, password, expected output }
           { Credentials("Jane Doe'--", "false_password"), "", errorMessage }, // Jared
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage },
           { Credentials("", ""), "", errorMessage }
   };

   /// test & validate
   runTests(testSet);

   delete testSet.testCases;
   testSet.testCases = nullptr;
}


 void runTests(TestSet & testSet) {
    cout << "\t" << testSet.name << ":\n";

    for (int i = 0; i < testSet.testsNumber; i++) {
       const string username = testSet.testCases[i].input.username;
       const string password = testSet.testCases[i].input.password;
       cout << "\t   Input (username/password):\n"
            << "\t      " << username << endl
            << "\t      " << password << endl;

       /// Test
       const string actualOutput = testSet.functionTested(username, password);

       /// Verify
       if (actualOutput == testSet.testCases[i].expectedOutput) {
         testSet.testCases[i].status = PASSED;
         testSet.testsPassedCount++;
         cout << "\t      PASSED: Nothing was injected\n";
       } else {
         testSet.testCases[i].status = FAILED;
         cout << "\t      FAILED: " << testSet.testCases[i].errorMessage << endl
              << "\t         Actual   output: " << actualOutput << endl
              << "\t         Expected output: " << testSet.testCases[i].expectedOutput << endl;
       }
    }

    /// Total
    cout << "\t==========================================================================\n"
         << "\t|| " << testSet.testsPassedCount << "/" << testSet.testsNumber << " tests passed for " << testSet.name << endl
         << "\t==========================================================================\n\n";
 }
