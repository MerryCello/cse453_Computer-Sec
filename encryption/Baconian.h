/********************************************************************
* Header:
*    Implement your cypher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef BACONIAN_H
#define BACONIAN_H

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
    * Returns the citation from which we learned about the cypher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Dupuy, Jr., Paul J. “The Advancement of Learning”, 2017, Accessed: July 15, 2021. \nAvailable [Online] ";
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
      str += "      cypherText += map.find(i)\n";
      str += "   RETURN cypherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cypherText, password)\n";
      str += "   FOR p is all values of cypherText\n";
      str += "      if string length != 7\n";
      str += "          string += cypherText[i]\n";
      str += "      else if string length == 7\n";
      str += "          plainText += map.find(string)\n";
      str += "          clear string\n";
      str += "          string += cypherText[i]\n";
      str += "   RETURN plainText\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * This encrypt() function will be passed a password and
    * some plain text. The plain text will be encrypted using
    * the Baconian Cypher (translating the text into 1's and
    * 0's) and then returning the cypherText.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password) {
      std::string cypherText; // Save the text after it has been encrypted

      for (int i = 0; i < plainText.length(); i++)
         cypherText += cypherMap[plainText[i]]; // Use the map variable that is declared as a private variable

      return cypherText;
   }

   /**********************************************************
    * DECRYPT
    * This decrypt() function will be passed a password and
    * some cypherText. The cypherText will be decrypted using
    * the Baconian Cypher (translating 1's and 0's into text)
    * in reverse and then returning the plainText.
    **********************************************************/
   virtual std::string decrypt(const std::string & cypherText,
                               const std::string & password) {
      std::string plainText; // Save the text after it has been decrypted

      for (const char c : cypherText)
         plainText += reverseMap(c);

      return plainText;
   }

/**********************************************************
 * REVERSEMAP
 * Instead of returning the value using the key in the map,
 * return the key with the value.
 **********************************************************/
   char reverseMap(char text) {
      for (auto & it : cypherMap) // Do the reverse of what the find() function does
         if (it.second == text)
            return it.first;
      return 'd';
   }

private:
   /**************************************************
    * MAP isalph -> 1's and 0's
    * Create a map that maps all symbols, digits, and
    * letters to a unique 7-bit binary number.
    *************************************************/
   std::map<char, char> cypherMap = {
           { 'a',  0b10000000 },
           { 'b',  0b10000001 },
           { 'c',  0b10000010 },
           { 'd',  0b10000011 },
           { 'e',  0b10000100 },
           { 'f',  0b10000101 },
           { 'g',  0b10000110 },
           { 'h',  0b10000111 },
           { 'i',  0b10001000 },
           { 'j',  0b10001001 },
           { 'k',  0b10001010 },
           { 'l',  0b10001011 },
           { 'm',  0b10001100 },
           { 'n',  0b10001101 },
           { 'o',  0b10001110 },
           { 'p',  0b10001111 },
           { 'q',  0b10010000 },
           { 'r',  0b10010001 },
           { 's',  0b10010010 },
           { 't',  0b10010011 },
           { 'u',  0b10010100 },
           { 'v',  0b10010101 },
           { 'w',  0b10010110 },
           { 'x',  0b10010111 },
           { 'y',  0b10011000 },
           { 'z',  0b10011001 },
           { 'A',  0b10011010 },
           { 'B',  0b10011011 },
           { 'C',  0b10011100 },
           { 'D',  0b10011101 },
           { 'E',  0b10011110 },
           { 'F',  0b10011111 },
           { 'G',  0b10100000 },
           { 'H',  0b10100001 },
           { 'I',  0b10100010 },
           { 'J',  0b10100011 },
           { 'K',  0b10100100 },
           { 'L',  0b10100101 },
           { 'M',  0b10100110 },
           { 'N',  0b10100111 },
           { 'O',  0b10101000 },
           { 'P',  0b10101001 },
           { 'Q',  0b10101010 },
           { 'R',  0b10101011 },
           { 'S',  0b10101100 },
           { 'T',  0b10101101 },
           { 'U',  0b10101110 },
           { 'V',  0b10101111 },
           { 'W',  0b10110000 },
           { 'X',  0b10110001 },
           { 'Y',  0b10110010 },
           { 'Z',  0b10110011 },
           { '0',  0b10110100 },
           { '1',  0b10110101 },
           { '2',  0b10110110 },
           { '3',  0b10110111 },
           { '4',  0b10111000 },
           { '5',  0b10111001 },
           { '6',  0b10111010 },
           { '7',  0b10111011 },
           { '8',  0b10111100 },
           { '9',  0b10111101 },
           { '!',  0b10111110 },
           { '@',  0b10111111 },
           { '#',  0b11000000 },
           { '$',  0b11000001 },
           { '%',  0b11000010 },
           { '^',  0b11000011 },
           { '&',  0b11000100 },
           { '*',  0b11000101 },
           { '(',  0b11000110 },
           { ')',  0b11000111 },
           { '-',  0b11001000 },
           { '_',  0b11001001 },
           { '=',  0b11001010 },
           { '+',  0b11001011 },
           { '[',  0b11001100 },
           { '{',  0b11001101 },
           { ']',  0b11001110 },
           { '}',  0b11001111 },
           { '\\', 0b11010000 },
           { '|',  0b11010001 },
           { ';',  0b11010010 },
           { ':',  0b11010011 },
           { '\'', 0b11010100 },
           { '"',  0b11010101 },
           { '<',  0b11010110 },
           { ',',  0b11010111 },
           { '>',  0b11011000 },
           { '.',  0b11011001 },
           { '/',  0b11011010 },
           { '?',  0b11011011 },
           { '`',  0b11011100 },
           { '~',  0b11011101 },
           { ' ',  0b11011110 },
           { '\n', 0b11011111 },
           { '\t', 0b11100000 }
   };
};

#endif // BACONIAN_H