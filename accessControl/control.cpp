/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    <your name here if you made a change>
 * Summary:
 *    This class stores the notion of Bell-LaPadula
 ************************************************************************/
#include <string>
#include "control.h"

using namespace std;


// Security Conditions
bool securityConditionRead(int assetControl, int subjectControl)
{
    return subjectControl >= assetControl;
}

bool securityConditionWrite(int assetControl, int subjectControl)
{
    return subjectControl <= assetControl;
}