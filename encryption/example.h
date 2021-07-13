/********************************************************************
* Header:
*    example.h
*    A simple Caesar Cipher to show what each header file should contain.
********************************************************************/
#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <cassert>

/********************************************************************
 * CLASS CIPHER
 *******************************************************************/
class Example : public Cipher
{
public:
   Example()
   {
      valueMinimum = ' ';
      valueMaximum = '~';
      sizeAlphabet = valueMaximum - valueMinimum + 1;
   }
   
   virtual std::string getPseudoAuth()  { return "Brother Helfrich"; } 
   virtual std::string getCipherName()  { return "Caesar Cipher";      }
   virtual std::string getEncryptAuth() { return "Brother Helfrich"; }
   virtual std::string getDecryptAuth() { return "Brother Helfrich"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "LearnCryptography.com (2016), ";
      s += "\"Learn Cryptography - Caesar Cipher\', \n   retrieved: ";
      s += "https://learncryptography.com/classical-encryption/caesar-cipher";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the psuedocode as a string to be used by the
    * caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encryptCase pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   offset <- offsetFromPassword(password)\n";
      str += "   FOR p is all values of plainText\n";
      str += "      index <- (indexFromCharacter(*p) + offset) % size\n";
      str += "      cipherText += characterFromIndex(index)\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   offset <- size - offsetFromPassword(password)\n";
      str += "   FOR p is all values of cipherText\n";
      str += "      index <- (indexFromCharacter(*p) + offset) % size\n";
      str += "      plainText += characterFromIndex(index)\n";
      str += "   RETURN plainText\n\n";

      // helper routine
      str += "offsetFromPassword(password)\n";
      str += "   FOR p is all values of password\n";
      str += "     offset <- indexFromCharacter(p)\n";
      str += "   RETURN offset % size\n\n";
      
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Shift every value in the plainText by a fixed amount
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string cipherText;

      // find a Caesar password from a textual password
      int offset = offsetFromPassword(password);
      assert(offset >= 0 && offset < sizeAlphabet);

      // convert the plaintext one character at a time
      for (const char * p = plainText.c_str(); *p; p++)
      {
         // convert the character into an index we can work with
         int index = indexFromCharacter(*p);

         // perform the shift
         index += offset;

         // make sure it is within range
         index %= sizeAlphabet;
         assert(index >= 0 && index < sizeAlphabet);

         // send the index into the ciphertext
         cipherText += characterFromIndex(index);
      }

      return cipherText;
   }

   /**********************************************************
    * DECRYPT 
    * Shift every value in cipherText by a fixed amount
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      std::string plainText;

      // find a Caesar password from a textual password
      int offset = offsetFromPassword(password);
      assert(offset >= 0 && offset < sizeAlphabet);

      // make the offset backwards
      offset = sizeAlphabet - offset;
      assert(offset >= 0 && offset < sizeAlphabet);

      // convert the plaintext one character at a time
      for (const char * p = cipherText.c_str(); *p; p++)
      {
         // convert the character into an index we can work with
         int index = indexFromCharacter(*p);

         // perform the shift
         index += offset;

         // make sure it is within range
         index %= sizeAlphabet;
         assert(index >= 0 && index < sizeAlphabet);

         // send the index into the ciphertext
         plainText += characterFromIndex(index);
      }

      return plainText;
   }

private:
   /**************************************************
    * INDEX FROM CHARACTER
    * Get an index value from a given letter.
    *************************************************/
   int indexFromCharacter(char letter)
   {
      // return the value
      if (letter > valueMaximum || letter < valueMinimum)
         return 0;
      else
         return (int)(letter - valueMinimum); 
   }

   /**************************************************
    * CHARACTER FROM INDEX
    * Get the characer value from a given index.
    *************************************************/
   char characterFromIndex(int index)
   {
      if (index >= 0 && index < sizeAlphabet)
         return (char)(index + valueMinimum);
      else
         return ' ';
   }

   /***************************************************
    * OFFSET FROM PASSWORD
    * Get the Caesar offset corresponding to a given password
    **************************************************/
   int offsetFromPassword(const std::string & password)
   {
      int offset = 0;
      for (std::string::const_iterator it = password.begin();
           it != password.end();
           ++it)
         offset += indexFromCharacter(*it);

      return offset % sizeAlphabet;
   }
   
   // minimum "printable" character
   char valueMinimum;

   // maximum "printable" character
   char valueMaximum;

   int sizeAlphabet;
};

#endif // EXAMPLE_H