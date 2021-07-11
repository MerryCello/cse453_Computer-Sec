/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class stores the notion of Bell-LaPadula
 ************************************************************************/
#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <map>

using namespace std;

// The 4 different levels of security.

enum Classifications {
   Public, Confidential, Privileged, Secret
};

class Control {
public:
   Control() : control(0) {};
   explicit Control(int control);
   explicit Control(string control);

   static bool securityConditionRead(int assetControl, int subjectControl);
   static bool securityConditionWrite(int assetControl, int subjectControl);

   Control& operator = (const string& rhs);
   Control& operator = (const int& rhs);
   operator int() const { return control; }
private:
   // The enum of type Classifications
   int control;
   // To make string/Control conversion easier
   map<string, int> classificationsMap = {
           { "Public",       Public       },
           { "Confidential", Confidential },
           { "Privileged",  Privileged    },
           { "Secret",       Secret       }
   };

   bool isValidClassification(int);
   bool isValidClassification(const string&);
};

#endif //PATHDEBUNKER_CPP_CONTROL_H
