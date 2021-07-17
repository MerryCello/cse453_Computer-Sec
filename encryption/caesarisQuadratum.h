/********************************************************************
 * File Author:
 *   Kevin Foniciello
 *
 * Cypher name:
 *   Caesar's square
 * Description:
 *   Transposition cypher.
 *   All cyphered text has a length of chars that form a square (i.e., 4, 9, 16, 25, etc.).
 *   The chars need to be put into that square to decode and encode.
 *   For example:
 *      Plaintext: 123456789 == forms a square ==> 147
 *                                                 258
 *                                                 369
 *      Encoded: 147258369
 *
 * Sources:
 *    https://www.dcode.fr/caesar-box-cipher
 *    https://everything2.com/title/caesar+square
 *    https://www.google.com/books/edition/Digital_Fortress/_FKPcZcTKNMC?gbpv=1 (pg 19)
 *******************************************************************/
#ifndef CAESARIS_QUADRATUM_H
#define CAESARIS_QUADRATUM_H

#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class CaesarisQuadratum : public Cipher {
private:
   string filler;

   static bool isPerfectSquare(const long long x) { return (sqrt(x) - floor(sqrt(x))) == 0; }

   static long long getNextPerfectSquare(const long long x) {
      if (isPerfectSquare(x))
         return x;

      // Finding first perfect square
      // number greater than n
      long long x1 = x + 1;
      while (true) {
         if (isPerfectSquare(x1))
            return x1;
         else
            x1++;
      }
   }

public:
   CaesarisQuadratum() { string str = "•"; this->filler = str[0]; }

   virtual string getPseudoAuth()  { return "Kevin Foniciello"; }
   virtual string getCipherName()  { return "Caesar's Square";  }
   virtual string getEncryptAuth() { return "Kevin Foniciello"; }
   virtual string getDecryptAuth() { return "Kevin Foniciello"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual string getCipherCitation() {
      string s;
      s += "everything2.com (2004), ";
      s += "\"Everything 2 - Caesar Square\", \n   retrieved: ";
      s += "https://everything2.com/title/caesar+square";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual string getPseudocode() {
      string str;

      // The encryptCase pseudocode
      str =  "encrypt(plainText, password)\n"
             "   size <- plainText.size()\n"
             "   perfectSquare <- getNextPerfectSquare(size)\n"
             "   widthSize <- sqrt(perfectSquare)\n"
             "   pt <- plainText\n"
             "   FOR i <- 0 WHILE i < (perfectSquare - size) INCR_BY i++\n"
             "      pt.append(filler)\n"
             "   FOR | i <- 0                                                     |\n"
             "       | WHILE (i + 1) != perfectSquare                             |\n"
             "       | INCR i by 1 IF (i+widthSize >= perfectSquare),             |\n"
             "       |      then ADD widthSize, then MOD the sum by perfectSquare |\n"
             "      cypherText.append(pt[i])\n"
             "   cypherText.append(pt[perfectSquare - 1])\n"
             "   RETURN cypherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n"
             "   plainText = encrypt(cypherText, password)\n"
             "   plainText.erase(remove(plainText.begin(), plainText.end(), filler), plainText.end())\n"
             "   RETURN plainText\n\n";

      // helper routine
      str += "getNextPerfectSquare(x)\n"
             "   IF isPerfectSquare(x)\n"
             "      RETURN x\n"
             "   x++\n"
             "   WHILE TRUE\n"
             "      IF isPerfectSquare(x)\n"
             "         RETURN x\n"
             "      ELSE\n"
             "         x++\n\n";

      // helper routine
      str += "isPerfectSquare(x)"
             "   RETURN (sqrt(x) - floor(sqrt(x))) IS_EQUAL_TO 0\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * A visual description says more with less comments:
    *      Plaintext: 123456789 == forms a square ==> 147
    *                                                 258
    *                                                 369
    *      Encoded: 147258369
    *      
    *      if plaintext.size is not a perfect square,
    *      then the rest is filled to be the size of a perfect square
    * @param password not needed to encrypt
    **********************************************************/
   virtual string encrypt(const string & plainText, const string & password) {
      string cypherText;

      // Prep plaintext before shuffling
      long long size = plainText.size();
      long long perfectSquare = getNextPerfectSquare(size);
      long widthSize = (long)sqrt(perfectSquare);
      string pt(plainText);
      for (int i = 0; i < (int)(perfectSquare - size); i++)
         pt += filler;

      // shuffle
      for (long long i = 0;
           (i + 1) != perfectSquare;
           i = (i + widthSize + ((i + widthSize) >= perfectSquare)) % perfectSquare) {
         cypherText += pt[i];
      }
      // add the last character that got skipped
      cypherText += *(--(pt.end()));

      return cypherText;
   }

   /**********************************************************
    * DECRYPT
    * Works the same as the encrypt function
    * @param password not used to decrypt
    **********************************************************/
   virtual string decrypt(const string & cypherText, const string & password) {
      string plainText = encrypt(cypherText, password);

      // Sift out filler chars
      plainText.erase(remove(plainText.begin(), plainText.end(), filler[0]), plainText.end());

      return plainText;
   }
};

#endif // CAESARIS_QUADRATUM_H