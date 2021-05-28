#include <iostream>
#include <string>

using namespace std;
typedef string (*GenQueryFunction)(string, string);

struct Credentials;
string genQuery(string, string);
string genQueryWeak(string, string);
string genQueryStrong(string, string);
void runTestCases(char);
//void runTests(string, GenQueryFunction, Credentials*, int, string);
void testValid(GenQueryFunction);
void testTautology(GenQueryFunction);
void testUnion(GenQueryFunction);
void testAddState(GenQueryFunction);
void testComment(GenQueryFunction);


int main() {
   char mitigationType = 'r';

   cout << "Options:\n"
        << "   r => Run tests on regular genQuery\n"
        << "   w => Run tests on weak    genQuery\n"
        << "   s => Run tests on strong  genQuery\n"
        << "   a => Run tests on on all genQueries\n\n";
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

string genQuery(string username, string password){
    // SELECT authenticate FROM passwordList WHERE name='$Username' and passwd='$Password'
    string sqlQuery = "SELECT authenticate FROM passwordList WHERE name='" + username + "' and passwd='" + password + "';";
    return sqlQuery;
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
      char invalidChars[] = {'<', '>', '&', ';', '"'};
      for (char invalidChar : invalidChars) {
         if (c == invalidChar) {
               cleanQuery += "";
               break;
         }
         cleanQuery += c;
      }
   }

   return cleanQuery;
}

/*******************************************************************
 * Strong Filter:
 *       - Allow only letters, numbers, and _
 *******************************************************************/
string genQueryStrong(string username, string password){
    // SELECT authenticate FROM passwordList WHERE name='$Username' and passwd='$Password'
    string sqlQuery = "SELECT authenticate FROM passwordList WHERE name='" + username + "' and passwd='" + password + "';";
    return sqlQuery;
}


/*******************************************************************
 * TESTS
 *******************************************************************/
void runTestCases(char mitigationType) {
   GenQueryFunction genQueryFunction = nullptr;
   string caseTitle;
   switch (mitigationType) {
      /// Regular
      case 'r': {
         caseTitle = "Running tests on \"genQuery()\"...\n";
         genQueryFunction = genQuery;
         break;
      }
      /// Weak
      case 'w': {
         caseTitle = "Running tests on \"genQueryWeak()\"...\n";
         genQueryFunction = genQueryWeak;
         break;
      }
      /// Strong
      case 's': {
         caseTitle = "Running tests on \"genQueryStrong()\"...\n";
         genQueryFunction = genQueryStrong;
         break;
      }
      /// All
      case 'a': {
         caseTitle = "Running tests on all genQueries...\n";
         genQueryFunction = nullptr;
         break;
      }

      default:
         throw "Uh oh, wrong option...";
   }

   /// Run all tests
   cout << caseTitle;
   if (!genQueryFunction) {
      GenQueryFunction functions[] = {genQuery, genQueryWeak, genQueryStrong};
      for (auto & function : functions) {
         testValid(function);
         testTautology(function);
         testUnion(function);
         testAddState(function);
         testComment(function);
      }
   }
   else {
      testValid(genQueryFunction);
      testTautology(genQueryFunction);
      testUnion(genQueryFunction);
      testAddState(genQueryFunction);
      testComment(genQueryFunction);
   }
}


// function testValid() {
//     genQuery("brian064", "secret")
//     genQuery("roger222", "secret")
//     genQuery("brian064", "secret")
//     genQuery("brian064", "secret")
//     genQuery("brian064", "secret")
// }
struct Credentials {
   string username;
   string password;
};

void testValid(GenQueryFunction genQueryFunction) {
   /// setup
   cout << "\nValid input:\n";
   // todo: setup test
   Credentials testValidCredentials[] = {
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" }
   };

   /// test
   for (auto & credential : testValidCredentials) {
      cout << "   Input (username/password):\n"
           << "      " << credential.username << endl
           << "      " << credential.password << endl;
      string query = genQueryFunction(credential.username, credential.password);

   /// verify
      // todo: properly verify
      if (query == "")
         cout << "      PASSED: Nothing was injected\n";
      else
         cout << "      FAILED: Query not properly build with VALID input\n";
   }
}


void testTautology(GenQueryFunction genQueryFunction) {
   /// setup
   cout << "\nTautology exploitation:\n";
   // todo: setup test
   Credentials testTautologyCredentials[] = {
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" }
   };

   /// test
   for (auto & credential : testTautologyCredentials) {
      cout << "   Input (username/password):\n"
           << "      " << credential.username << endl
           << "      " << credential.password << endl;
      string query = genQueryFunction(credential.username, credential.password);

   /// verify
      // todo: properly verify
      if (query == "")
         cout << "      PASSED: Nothing was injected\n";
      else
         cout << "      FAILED: Query failed due to a BOOLEAN attack\n";
   }
}


void testUnion(GenQueryFunction genQueryFunction) {
   /// setup
   cout << "\nUnion exploitation:\n";
   // todo: setup test
   Credentials testUnionCredentials[] = {
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" }
   };

   /// test
   for (auto & credential : testUnionCredentials) {
      cout << "   Input (username/password):\n"
           << "      " << credential.username << endl
           << "      " << credential.password << endl;
      string query = genQueryFunction(credential.username, credential.password);

   /// verify
      // todo: properly verify
      if (query == "")
         cout << "      PASSED: Nothing was injected\n";
      else
         cout << "      FAILED: Query was altered to execute a UNION\n";
   }
}


void testAddState(GenQueryFunction genQueryFunction) {
   /// setup
   cout << "\nAdd State exploitation:\n";
   // todo: setup test
   Credentials testAddStateCredentials[] = {
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" }
   };

   /// test
   for (auto & credential : testAddStateCredentials) {
      cout << "   Input (username/password):\n"
           << "      " << credential.username << endl
           << "      " << credential.password << endl;
      string query = genQueryFunction(credential.username, credential.password);

   /// verify
      // todo: properly verify
      if (query == "")
         cout << "      PASSED: Nothing was injected\n";
      else
         cout << "      FAILED: A state was added to the query\n";
   }
}


void testComment(GenQueryFunction genQueryFunction) {
   /// setup
   cout << "\nComment exploitation:\n";
   // todo: setup test
   Credentials testCommentCredentials[] = {
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" },
           { "", "" }
   };

   /// test
   for (auto & credential : testCommentCredentials) {
      cout << "   Input (username/password):\n"
           << "      " << credential.username << endl
           << "      " << credential.password << endl;
      string query = genQueryFunction(credential.username, credential.password);

   /// verify
      // todo: properly verify
      if (query == "")
         cout << "      PASSED: Nothing was injected\n";
      else
         cout << "      FAILED: Comments altered how the query should have run\n";
   }
}


//enum TestStatuses {
//   TODO = 0,
//   FAILED = 1,
//   PASSED = 2
//};
//
//struct Test {
//   string name;
//   bool (*run)(Credentials*);
//   TestStatuses status = TODO;
//};


// void runTests(string testName, GenQueryFunction genQueryFunction, Credentials* testCredentials, int testsNumber, string errorMessage) {
//
//    cout << "\nRunning tests on " << testName << "...\n";
//
//    int testsPassedCount = 0;
//    for (int i = 0; i < testsNumber; i++) {
//       cout << "   Input (username/password):\n"
//            << "      " << testCredentials[i].username << endl
//            << "      " << testCredentials[i].password << endl;
//       string query = genQueryFunction(testCredentials[i].username, testCredentials[i].password);
//       cout << "      PASSED: Nothing was injected\n";
//       cout << "      FAILED: " << errorMessage << endl;
//    }
//    for (int i = 0; i < numberOfTests; i++) {
//       bool testPassed = tests[i].run();
//       if (testPassed) {
//          cout << "\t..." << "PASSED\n\n";
//          tests[i].status = PASSED;
//          testsPassedCount++;
//       } else {
//          cout << "\t...FAILED\n\n";
//          tests[i].status = FAILED;
//       }
//    }
//
//    cout << "==========================================================================\n"
//         << testsPassedCount << "/" << numberOfTests << " tests passed\n";
// }


// /**
//  * Homographs Test 1
//  * @return
//  */
// bool test1() {
//    // Setup
//    // Test
//    // Verify
//    return false;
// }



// /**
//  * Display a detailed test case report 
//  */
// void detailedTestCaseReport(string actualPath1, string inputPath1,
//                             string actualPath2, string inputPath2) {
// }
