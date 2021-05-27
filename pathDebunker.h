#ifndef COMPUTERSECURITY_PATHDEBUNKER_H
#define COMPUTERSECURITY_PATHDEBUNKER_H

#include <string>
#include <list>

using namespace std;

string retrievePath();
string canonizePath(string &);
list<string> split(string, char);
list<string> simplifyPath(list<string>::iterator currentDir,
                          list<string> & inputPath);
bool pathsAreHomographs(string, string);
void runTests();
bool test1();
bool test2();
bool test3();
bool test4();
bool test5();
bool test6();
void detailedTestCaseReport(string, string, string, string);

#endif //COMPUTERSECURITY_PATHDEBUNKER_H
