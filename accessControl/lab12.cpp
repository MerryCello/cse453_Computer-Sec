/***********************************************************************
* Program:
*    Lab 12, Bell-LaPadula
* Author:
*    Br. Helfrich, <your name here if you made a change>
* Summary:
*    This program is designed to keep track of a number of secret
*    messages. IT will display messages to the appropriate users
*    and withhold messages from those lacking the authority.
************************************************************************/

#include <iostream>   // standard input and output
#include <string>     // for convenience
#include <cassert>    // because I am paranoid
#include "interact.h" // the interaction code
#include "messages.h" // the collection of messages
using namespace std;

// TODO: change this back to what it was
// const char * FILE_NAME = "messages.txt";
const char * FILE_NAME = "C:\\Users\\kevin\\Downloads\\messages.txt";


/***********************************************
 * DISPLAY OPTIONS
 ***********************************************/
void displayOptions()
{
   cout << "\td .. Display the list of messages\n";
   cout << "\ts .. Show one message\n";
   cout << "\ta .. Add a new message\n";
   cout << "\tu .. Update an existing message\n";
   cout << "\tr .. Delete an existing message\n";
   cout << "\to .. Display this list of options\n";
   cout << "\tl .. Log out\n";
}

/************************************************
 * SIMPLE PROMPT
 ************************************************/
string simplePrompt(const char * prompt)
{
   string input;
   cout << prompt;
   cin  >> input;
   return input;
}

/***************************************************
 * SESSION
 * One login session
 **************************************************/
void session(Messages & messages)
{
   displayUsers();
   string userName = simplePrompt("What is your username? ");
   string password = simplePrompt("What is your password? ");

   // start a session
   Interact interact(userName, password, messages);
   cout << "Welcome, " << userName << " please select an option:\n";
   displayOptions();

   // inteact loop
   while (true)
   {
      char option;
      cout << "\n<" << userName << "> ";
      cin  >> option;
      cin.ignore();

      switch (option)
      {
         case 'o':
            displayOptions();
            break;
         case 'd':
            interact.display();
            break;
         case 's':
            interact.show();
            break;
         case 'a':
            interact.add();
            break;
         case 'u':
            interact.update();
            break;
         case 'r':
            interact.remove();
            break;
         case 'l':
            cout << "Goodbye, " << userName << ".\n";
            return;
         default:
            cout << "Unknown option: '" << option << "'\n";
            break;
      }
   }
}

/***************************************************
 * MAIN
 * Where it all begins and where it all ends
 ***************************************************/
int main()
{
   Messages messages(FILE_NAME);

   bool done;
   do
   {
      session(messages);

      char selection;
      cout << "Will another user be logging in? (y/n) ";
      cin >> selection;
      cin.ignore();
      done = (selection == 'y' || selection == 'Y') ? false : true;
   }
   while (!done);

   return 0;
}
