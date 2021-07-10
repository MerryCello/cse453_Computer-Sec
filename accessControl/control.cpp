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


Control::Control(int control) {
   if (isValidClassification(control))
      this->control = control;
   else
      this->control = 0;
}


Control::Control(string control) {
   if (isValidClassification(control))
      this->control = classificationsMap[control];
   else
      this->control = 0;
}


// Security Conditions
bool Control::securityConditionRead(int assetControl, int subjectControl) {
    return subjectControl >= assetControl;
}


bool Control::securityConditionWrite(int assetControl, int subjectControl) {
    return subjectControl <= assetControl;
}


/**
 * Verifies that rhs is one of the Classifications before assigning.
 * If not, then the lesser one is assigned
 * @param rhs Right-Hand Side argument
 */
Control& Control::operator=(const string& rhs) {
   if (isValidClassification(rhs)) // i.e., not found
      this->control = classificationsMap[rhs]; // i.e., the enum
   else
      this->control = 0; // i,e,. The lesser one (Public)

   return *this;
}


/**
 * Verifies that rhs is one of the Classifications before assigning.
 * If not, then the lesser one is assigned
 * @param rhs Right-Hand Side argument
 */
Control& Control::operator=(const int& rhs) {
   if (isValidClassification(rhs))
      this->control = rhs;

   // when rhs value not found, give it the lesser one (Public).
   // 0 is assigned to make it more maintainable. Imaging changing
   // the keyword Public to basic, then you would have to change
   // the code here too if Public was assigned rather than 0.
   else
      this->control = 0;

   return *this;
}


bool Control::isValidClassification(int classification) {
   for (auto & it : classificationsMap) {
      if (it.second == classification) {
         return true;
      }
   }
   return false;
}


bool Control::isValidClassification(const string& classificationStr) {
   auto it = classificationsMap.find(classificationStr);
   if (it == classificationsMap.end()) // i.e., not found
      return false;
   else
      return true;
}
