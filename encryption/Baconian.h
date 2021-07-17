/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <iostream>
#include <map>

/********************************************************************
 * CLASS
 *******************************************************************/
class Baconian : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Paul Semadeni"; }
   virtual std::string getCipherName()  { return "Baconian Cipher"; }
   virtual std::string getEncryptAuth() { return "Paul Semadeni"; }
   virtual std::string getDecryptAuth() { return "Paul Semadeni"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Dupuy, Jr., Paul J. \"The Advancement of Learning\", 2017, Accessed: July 15, 2021. \nAvailable [Online] ";
      s += "http://home.hiwaay.net/~paul/bacon/advancement/book6ch1.html";
      return s;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encryptCase pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   FOR i is all values of plainText\n";
      str += "      cipherText += map.find(i)\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   FOR p is all values of cipherText\n";
      str += "      if string length != 7\n";
      str += "          string += cipherText[i]\n";
      str += "      else if string length == 7\n";
      str += "          plainText += map.find(string)\n";
      str += "          clear string\n";
      str += "          string += cipherText[i]\n";
      str += "   RETURN plainText\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * This encrypt() function will be passed a password and
    * some plain text. The plain text will be encrypted using
    * the Baconian Cypher (translating the text into 1's and
    * 0's) and then returning the cipherText.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText; // Save the text after it has been encrypted

      for (int i = 0; i < plainText.length(); i++)
      {
         cipherText += cipherMap.find(plainText[i])->second; // Use the map variable that is declared as a private variable
      }

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * This decrypt() function will be passed a password and
    * some cipherText. The cipherText will be decrypted using
    * the Baconian Cypher (translating 1's and 0's into text)
    * in reverse and then returning the plainText.
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText; // Save the text after it has been decrypted
      std::string str; // Save 7 bits of digits every iteration

      for (int i = 0; i < cipherText.length(); i++)
      {
         if (str.length() != 7) // As long as str is not 7 bits long, keep iterating
         {
            str += cipherText[i];
         }
         else if (str.length() == 7) // Once str is 7 bits long, pass it to the reverseMap function
         {
            plainText += reverseMap(str);
            str.clear();
            str += cipherText[i];
         }
      }

      plainText += reverseMap(str);

      return plainText;
   }

/**********************************************************
 * REVERSEMAP
 * Instead of returning the value using the key in the map,
 * return the key with the value.
 **********************************************************/
   std::string reverseMap(std::string text) {
      std::string str;

      for (auto it = cipherMap.begin(); it != cipherMap.end(); ++it) // Do the reverse of what the find() function does
         {
            if (it->second == text)
               str += it->first;
         }

      return str;
   }

private:
   /**************************************************
    * MAP isalph -> 1's and 0's
    * Create a map that maps all symbols, digits, and
    * letters to a unique 7-bit binary number.
    *************************************************/
   std::map<char, std::string> cipherMap = {
           { 'a', "0000000" },
           { 'b', "0000001" },
           { 'c', "0000010" },
           { 'd', "0000011" },
           { 'e', "0000100" },
           { 'f', "0000101" },
           { 'g', "0000110" },
           { 'h', "0000111" },
           { 'i', "0001000" },
           { 'j', "0001001" },
           { 'k', "0001010" },
           { 'l', "0001011" },
           { 'm', "0001100" },
           { 'n', "0001101" },
           { 'o', "0001110" },
           { 'p', "0001111" },
           { 'q', "0010000" },
           { 'r', "0010001" },
           { 's', "0010010" },
           { 't', "0010011" },
           { 'u', "0010100" },
           { 'v', "0010101" },
           { 'w', "0010110" },
           { 'x', "0010111" },
           { 'y', "0011000" },
           { 'z', "0011001" },
           { 'A', "0011010" },
           { 'B', "0011011" },
           { 'C', "0011100" },
           { 'D', "0011101" },
           { 'E', "0011110" },
           { 'F', "0011111" },
           { 'G', "0100000" },
           { 'H', "0100001" },
           { 'I', "0100010" },
           { 'J', "0100011" },
           { 'K', "0100100" },
           { 'L', "0100101" },
           { 'M', "0100110" },
           { 'N', "0100111" },
           { 'O', "0101000" },
           { 'P', "0101001" },
           { 'Q', "0101010" },
           { 'R', "0101011" },
           { 'S', "0101100" },
           { 'T', "0101101" },
           { 'U', "0101110" },
           { 'V', "0101111" },
           { 'W', "0110000" },
           { 'X', "0110001" },
           { 'Y', "0110010" },
           { 'Z', "0110011" },
           { '0', "0110100" },
           { '1', "0110101" },
           { '2', "0110110" },
           { '3', "0110111" },
           { '4', "0111000" },
           { '5', "0111001" },
           { '6', "0111010" },
           { '7', "0111011" },
           { '8', "0111100" },
           { '9', "0111101" },
           { '!', "0111110" },
           { '@', "0111111" },
           { '#', "1000000" },
           { '$', "1000001" },
           { '%', "1000010" },
           { '^', "1000011" },
           { '&', "1000100" },
           { '*', "1000101" },
           { '(', "1000110" },
           { ')', "1000111" },
           { '-', "1001000" },
           { '_', "1001001" },
           { '=', "1001010" },
           { '+', "1001011" },
           { '[', "1001100" },
           { '{', "1001101" },
           { ']', "1001110" },
           { '}', "1001111" },
           { '\\', "1010000" },
           { '|', "1010001" },
           { ';', "1010010" },
           { ':', "1010011" },
           { '\'', "1010100" },
           { '"', "1010101" },
           { '<', "1010110" },
           { ',', "1010111" },
           { '>', "1011000" },
           { '.', "1011001" },
           { '/', "1011010" },
           { '?', "1011011" },
           { '`', "1011100" },
           { '~', "1011101" },
           { ' ', "1011110" },
           { '\n', "1011111" },
           { '\t', "1100000" }
   };

};

#endif // CIPHER03_H