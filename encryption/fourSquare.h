/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef FOUR_SQUARE_H
#define FOUR_SQUARE_H

using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class FourSquare : public Cipher {
private:
   string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_=+{}[]|:<,>.?£€¢¥§°";

public:
   virtual string getPseudoAuth()  { return "Jared Aston";        }
   virtual string getCipherName()  { return "Four Square Cipher"; }
   virtual string getEncryptAuth() { return "Jared Aston";        }
   virtual string getDecryptAuth() { return "Jared Aston";        }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual string getCipherCitation() {
      return "\"Four-Square Cipher\" (2020, March 9). Retrieved On July 16, 2021. "
             "Retrieved From http://www.crypto-it.net/eng/simple/four-square.html";
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual string getPseudocode() {
      string str;

      // The encrypt pseudocode
      str =  "encrypt()\n";
      str += "   set postion to 0\n";
      str += "   while position < length\n";
      str += "      if position++ < length\n";
      str += "         take two characters from plaintext and add to string and 2 to position\n";
      str += "      else place stand-in Q value in second space in string and add 1 to position\n";
      str += "         find values in string from alphabet\n";
      str += "      swap values in top left and bottom right squares using password\n";
      str += "      swap message values according to 5x19 squares\n";
      str += "   combine values into one ciphertext and return\n";

      // The decrypt pseudocode
      str += "decrypt()\n";
      str += "   'Ciphertext decryption is performed in a similar way.'\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual string encrypt(const string & plainText,
                          const string & password) {
      int position = 0;
      string cipherText;
      while (position < plainText.length()) {
         string message = to_string(plainText[position]);
         string formatMsg;

         if (position + 1 < plainText.length()) {
            formatMsg = plainText[position + 1];
            position += 2;
         } else {
            formatMsg = 'Q';
            position += 1;
         }
//         string tpLeft = to_string(alphabet[alphabet.find(message)]);
//         string btmRight = to_string(alphabet[alphabet.find(formatMsg)]);
         // TODO: fix. What are you trying to do here? You're trying to access password like it's a 2D array
//         string square1 = password[0][(19 * floor(int(tpLeft.c_str()) / 5)) + int(btmRight.c_str()) % 5];
//         string square2 = password[1][(19 * floor(int(btmRight.c_str()) / 5)) + int(tpLeft.c_str()) % 5];
//         cipherText += (square1 + square2);
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual string decrypt(const string & cipherText,
                          const string & password) {
      int position = 0;
      string plainText;
      while (position < cipherText.length()) {
         string message = to_string(cipherText[position]);
         string formatMsg;

         if (position + 1 < cipherText.length()) {
            formatMsg = cipherText[position + 1];
            position += 2;
         } else {
            formatMsg = 'Q';
            position += 1;
         }
//         string tpLeft = to_string(alphabet[alphabet.find(message)]);
//         string btmRight = to_string(alphabet[alphabet.find(message)]);
         // TODO: fix. What are you trying to do here? You're trying to access password like it's a 2D array
//         string square1 = password[0][(19 * floor(int(tpLeft.c_str()) / 5)) + int(btmRight.c_str()) % 5];
//         string square2 = password[1][(19 * floor(int(btmRight.c_str()) / 5)) + int(tpLeft.c_str()) % 5];
//         plainText += square1 + square2;
      }
      return plainText;
   }
};

#endif // FOUR_SQUARE_H