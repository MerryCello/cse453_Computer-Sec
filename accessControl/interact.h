/***********************************************************************
 * COMPONENT:
 *    INTERACT
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class allows one user to interact with the system
 ************************************************************************/
#ifndef INTERACT_H
#define INTERACT_H


#include <string>     // for convenience
#include "messages.h" // to interact with the collection of messages
#include "./control.h"  // all the Bell-LaPadula stuff

/**************************************************************
 * USER
 * All the users currently in the system
 *************************************************************/
struct User
{
   // User(string name, string password, Control control) {
   //    name = name.c_str();
   //    password = password.c_str();
   //    accessControl = control;
   // }
   const char *name;
   const char *password;
   Control accessControl;
};

/****************************************************
 * INTERACT
 * One user interacting with the system
 ***************************************************/
class Interact
{
public:
   Interact(const std::string & userName,
            const std::string & password,
            Messages & messages);

   // show a single message
   void show() const;

   // display the set of messages
   void display() const;

   // display an "access denied" message
   static void displayAccessDenied() ;

   // add a single message
   void add();

   // update a single message
   void update();

   // remove one message from the list
   void remove();

private:
   Messages * pMessages;
   std::string userName;

   // prompt for a line of input
   std::string promptForLine(const char * verb) const;

   // prompt for a message ID
   int promptForId(const char * verb) const;

   // authenticate the user;
   Control authenticate(const std::string & userName,
                     const std::string & password);

   // find the ID of a given user
   int idFromUser(const std::string & userName) const;
};

// display the set of users in the system
void displayUsers();


#endif //PATHDEBUNKER_CPP_INTERACT_H
