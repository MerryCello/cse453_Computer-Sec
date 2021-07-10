/***********************************************************************
 * COMPONENT:
 *    MESSAGE
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class stores the notion of a message
 ************************************************************************/

#include <iostream>   // standard input and output
#include <cassert>    // because I am paraniod
#include "message.h"  // for the header file
using namespace std;

/**************************************************
 * MESSAGE DEFAULT CONSTRUCTOR
 * Set a message to empty
 **************************************************/
Message:: Message()
{
   empty = true;
   text = "Empty";
   id = idNext++;
}

/**************************************************
 * MESSAGE NON-DEFAULT CONSTRUCTOR
 * Create a message and fill it
 **************************************************/
Message::Message(const string & text,
                 const string & author,
                 const string & date,
                 const Control & textControl)
{
   this->text = text;
   this->author = author;
   this->date = date;
   this->textControl = textControl;
   this->id = idNext++;
   empty = false;
}

/**************************************************
 * MESSAGE :: DISPLAY PROPERTIES
 * Display the attributes/properties but not the
 * content of this message
 **************************************************/
void Message::displayProperties() const
{
   // skip this one if there is nothing to see
   if (empty)
      return;

   // display the message
   cout << "\t[" << id << "] ";
   cout << "Message from " << author << " at " << date;
   cout << endl;
}

/**************************************************
 * MESSAGE :: DISPLAY TEXT
 * Display the contents or the text of the message
 **************************************************/
void Message::displayText() const
{
   cout << "\tMessage: "
        << text
        << endl;
}

/**************************************************
 * MESSAGE :: UPDATE TEXT
 * Update the contents or text of the message
 **************************************************/
void Message::updateText(const string & newText)
{
   text = newText;
}

/**************************************************
 * MESSAGE :: CLEAR
 * Delete the contents of a message and mark it as empty
 *************************************************/
void Message::clear()
{
   text = "Empty";
   author.clear();
   date.clear();
   empty = true;
}

int Message::idNext = 100;