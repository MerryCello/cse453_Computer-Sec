/***********************************************************************
 * COMPONENT:
 *    MESSAGES
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class stores the notion of a collection of messages
 ************************************************************************/
#ifndef MESSAGES_H
#define MESSAGES_H


// #pragma once

#include <string>     // for convenience
#include <list>       // to store the messages
#include "control.h"  // all the Bell-LaPadula code
#include "message.h"  // all the code about a single message

/***********************************************
 * MESSAGES
 * The collection of high-tech messages
 ***********************************************/
class Messages
{
public:
   // constructor: read a file to fill the messages
   Messages(const char * fileName) { readMessages(fileName); }

   // get a message by it's id
   int getMessageTextControl(int messageId);

   // display the list of messages
   void display() const;

   // show a single message
   void show(int id) const;

   // update one single message
   void update(int id,
               const std::string & text);

   // remove a single message
   void remove(int id);

   // add a new message
   void add(const std::string & text,
            const std::string & author,
            const std::string & date,
            const int & textControl);

private:
   // the list of messages
   std::list <Message> messages;

   // read the messages from a file
   void readMessages(const char * fileName);
};


#endif //PATHDEBUNKER_CPP_MESSAGES_H
