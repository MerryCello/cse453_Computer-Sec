/***********************************************************************
* COMPONENT:
*    MESSAGE
* Author:
*    Br. Helfrich, <your name here if you made a change>
* Summary:
*    This class stores the notion of a message
************************************************************************/
#ifndef MESSAGE_H
#define MESSAGE_H


// #pragma once

#include <string>     // for convenience
#include "control.h"  // for all the control stuff


/**************************************************
 * MESSAGE
 * one message to be displayed to the user or not
 **************************************************/
class Message
{
public:
   // default constructor for an empty message
   Message();

   // the most commonly used constructor: create a message
   Message(const std::string & text,
           const std::string & author,
           const std::string & date,
           const int & textControl);

   // determine the unique ID of this message
   int getID() const { return id; }

   // determine the text control of this message
   int getTextControl() const { return textControl; }

   // display the properties but not content of the message
   void displayProperties() const;

   // display the content of the message
   void displayText() const;

   // update the text componet of the message
   void updateText(const std::string & newText);

   // clear out a message
   void clear();

private:
   int id;                   // the unique ID of this message
   static int idNext;        // the id of the next message created
   bool empty;               // is this message empty / cleared?
   std::string text;         // the textual content of this message
   std::string author;       // the author of this message
   std::string date;         // the date this message was created
   int textControl;  // the confidentiallity level
};


#endif //PATHDEBUNKER_CPP_MESSAGE_H
