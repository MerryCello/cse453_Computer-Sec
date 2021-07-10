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

// #pragma once

// The 4 different levels of security.
enum Control {
    Public, Confidential, Privileged, Secret
};

// To make string/Control conversion easier
// TODO: Issue compiling because this is a global variable
map<string, Control> ControlMap = {
   { "Public",       Public       },
   { "Confidential", Confidential },  
   { "Priviledged",  Privileged  },
   { "Secret",       Secret       }
};

bool securityConditionRead(int assetControl, int subjectControl);
bool securityConditionWrite(int assetControl, int subjectControl);


#endif //PATHDEBUNKER_CPP_CONTROL_H
