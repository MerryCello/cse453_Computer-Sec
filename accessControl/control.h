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
#include "interact.h"

using namespace std;

// #pragma once

// The 4 different levels of security.
enum Control {
    Public, Confidential, Priviledged, Secret
};

// To make string/Control conversion easier
map<string, Control> ControlMap = {
   { "Public",       Public       },
   { "Confidential", Confidential },  
   { "Priviledged",  Priviledged  },
   { "Secret",       Secret       }
};

bool securityConditionRead(int assetControl, int subjectControl);
bool securityConditionWrite(int assetControl, int subjectControl);


#endif //PATHDEBUNKER_CPP_CONTROL_H
