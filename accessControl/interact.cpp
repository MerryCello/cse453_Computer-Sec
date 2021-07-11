/***********************************************************************
 * COMPONENT:
 *    INTERACT
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class allows one user to interact with the system
 ************************************************************************/

#include <iostream>    // standard input and output
#include <string>      // for convenience
#include <cassert>     // because I am paraniod
#include <stdlib.h>    // for atoi
#include "messages.h"  // to interact with the collection of messages
#include "./control.h" // all the Bell-LaPadula stuff
#include "interact.h"  // the interact class and User structure

using namespace std;

/**************************************************************
 * USERS
 * All the users currently in the system
 *************************************************************/
const User users[] =
        {
                { "AdmiralAbe",     "password", Control(Secret)       },
                { "CaptainCharlie", "password", Control(Privileged)   },
                { "SeamanSam",      "password", Control(Confidential) },
                { "SeamanSue",      "password", Control(Confidential) },
                { "SeamanSly",      "password", Control(Confidential) }
        };

const int ID_INVALID = -1;

/****************************************************
 * INTERACT constructor
 * Authenticat ethe user and get him/her all set up
 ***************************************************/
Interact::Interact(const string & userName,
                   const string & password,
                   Messages & messages)
{
   this->userName = userName;
   this->pMessages = &messages;
   Control control = authenticate(userName, password);
}

/****************************************************
 * INTERACT :: SHOW
 * show a single message
 ****************************************************/
void Interact::show() const
{
   int messageId = promptForId("display");
   int assetControl = pMessages->getMessageTextControl(messageId);
   int subjectControl = users[idFromUser(userName)].accessControl;

   if (Control::securityConditionRead(assetControl, subjectControl))
      pMessages->show(messageId);
   else
      displayAccessDenied();
}

/****************************************************
 * INTERACT :: DISPLAY
 * display the set of messages
 ***************************************************/
void Interact::display() const
{
   pMessages->display();
}


/****************************************************
 * INTERACT :: DISPLAY_ACCESS_DENIED
 * display an "access denied" message
 ***************************************************/
void Interact::displayAccessDenied() {
   cout << "*** ACCESS DENIED ***\n";
}


/****************************************************
 * INTERACT :: ADD
 * add a single message
 ****************************************************/
void Interact::add()
{
   pMessages->add(promptForLine("message"),
                  userName,
                  promptForLine("date"),
                  users[idFromUser(userName)].accessControl); // New message inherits user's accessControl
}

/****************************************************
 * INTERACT :: UDPATE
 * update a single message
 ****************************************************/
void Interact::update()
{
   int messageId = promptForId("update");
   int assetControl = pMessages->getMessageTextControl(messageId);
   int subjectControl = users[idFromUser(userName)].accessControl;

   if (Control::securityConditionWrite(assetControl, subjectControl)) {
      pMessages->update(messageId, promptForLine("message"));
   }
   else {
      displayAccessDenied();
   }
}

/****************************************************
 * INTERACT :: REMOVE
 * remove one message from the list
 ***************************************************/
void Interact::remove()
{
   int messageId = promptForId("delete");
   int assetControl = pMessages->getMessageTextControl(messageId);
   int subjectControl = users[idFromUser(userName)].accessControl;

   if (Control::securityConditionRead(assetControl, subjectControl)) {
      pMessages->remove(messageId);
   }
   else {
      displayAccessDenied();
   }
}

/****************************************************
 * INTERACT :: DISPLAY USERS
 * display the set of users in the system
 ***************************************************/
void displayUsers()
{
   for (int idUser = 0; idUser < sizeof(users) / sizeof(users[0]); idUser++)
      cout << "\t" << users[idUser].name << endl;
}

/****************************************************
 * INTERACT :: PROMPT FOR LINE
 * prompt for a line of input
 ****************************************************/
string Interact::promptForLine(const char * verb) const
{
   string line;
   cout << "Please provide a " << verb << ": ";
   getline(cin, line);
   return line;
}

/****************************************************
 * INTERACT :: PROMPT FOR ID
 * prompt for a message ID
 ***************************************************/
int Interact::promptForId(const char * verb) const
{
   string id;
   cout << "Select the message ID to " << verb << ": ";
   cin  >> id;
   cin.ignore();
   return atoi(id.c_str());
}

/****************************************************
 * INTERACT :: AUTHENTICATION
 * authenticate the user: find their control level
 ****************************************************/
Control Interact::authenticate(const string & userName,
                            const string & password)
{
   int id = idFromUser(userName);
   bool authenticated = false;
   if (ID_INVALID != id && password == string(users[id].password))
      authenticated = true;

   if (authenticated) {
      return users[id].accessControl;
   }
   else {
      this->userName = "unAuth"; // Change it to something else that's not in the users' list

      //Return Public access
      return Control(0);
   }
}

/****************************************************
 * INTERACT :: ID FROM USER
 * Find the ID of a given user
 ****************************************************/
int Interact::idFromUser(const string & userName) const
{
   for (int idUser = 0; idUser < sizeof(users) / sizeof(users[0]); idUser++)
      if (userName == string(users[idUser].name))
         return idUser;
   return ID_INVALID;
}
