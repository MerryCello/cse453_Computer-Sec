/********************************************************************
* File Author: Brian Aguilar
* Cypher Name: Zig Zag Route Cypher
* Description:
*  The cipher will create a two dimensional grid using the password size
*  for the row size and the plaintext + password size for the columns. Then,
*  the characters of the plaintext + password text will be added into the grid
*  one by one. After, the characters in the grid will be appended to the ciphertext
*  one by one in a zig zag pattern from the top left of the grid all the way to the
*  end of it. Then to decrypt, the ciphertext will be added into the same grid
*  in reverse and the reverse of the pattern (minus the size of the password)
*  will be used to derive the original plaintext.
*
* Example:
*  Plaintext: JarelBrian
*  Password: Toy (String size determines the row size)
*  Encryption:
*  Grid:       Resulting ciphertext using Zig zag Pattern:
*     JAR         JARBLERIAOTNY**
*     ELB
*     RIA
*     NTO
*     Y**
*
*
*  Decryption:
*  Grid:       Resulting plaintext using  reverse Zig zag Pattern - Password size:
*     **Y         JARELBRIAN
*     NTO
*     AIR
*     ELB
*     RAJ
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class ZigZagRoute : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Brian Aguilar"; }
   virtual std::string getCipherName()  { return "Zig Zag Route Cipher"; }
   virtual std::string getEncryptAuth() { return "Brian Aguilar"; }
   virtual std::string getDecryptAuth() { return "Brian Aguilar"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("http://www.crypto-it.net/eng/simple/route-cipher.html");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "--ENCRYPT PSEUDOCODE--\n";
      str +=  "   intitialize cipherText\n";
      str +=  "   intitialize gridText to plaintext plus password\n";
      str +=  "   \n";
      str +=  "   initialize columns to password's size\n";
      str +=  "   initialize rows to gridText's size\n";
      str +=  "   \n";
      str +=  "   set row to zero\n";
      str +=  "   set col to zero\n";
      str +=  "   set colStart to zero\n";
      str +=  "   set colEnd to columns size minus one\n";
      str +=  "   \n";
      str +=  "   while counter is less than size of gridText starting from 0, loop through gridText characters\n";
      str +=  "       if the current gridText character is valid\n";
      str +=  "           set current grid coordinates to the gridText character\n";
      str +=  "   \n";
      str +=  "           increment col by one\n";
      str +=  "   \n";
      str +=  "           if col is greater than colEnd\n";
      str +=  "               set col to zero\n";
      str +=  "               increment row\n";
      str +=  "   \n";
      str +=  "   set row back to 0\n";
      str +=  "   set col back to 0\n";
      str +=  "   initialize direction to 'forward'\n";
      str +=  "   \n";
      str +=  "   while counter is less than gridText size starting from zero, increment through the grid\n";
      str +=  "       if direction equals 'forward'\n";
      str +=  "           add the value of the current grid coordinates to cipherText\n";
      str +=  "           increment col by one\n";
      str +=  "   \n";
      str +=  "           if col is greater than colEnd\n";
      str +=  "               set col to colEnd\n";
      str +=  "               increment row by one\n";
      str +=  "               change direction to 'backward'\n";
      str +=  "   \n";
      str +=  "       if direction equals 'backward'\n";
      str +=  "           add the value of the current grid coordinates to cipherText\n";
      str +=  "           decrement col by one\n";
      str +=  "   \n";
      str +=  "           if col is less than colStart\n";
      str +=  "               set col to colStart\n";
      str +=  "               increment row by one\n";
      str +=  "               change direction to 'forward'\n";
      str +=  "   \n";
      str +=  "   return the cipherText\n\n\n";

      // The decrypt pseudocode
      str +=  "--DECRYPT PSEUDOCODE--\n";
      str +=  "   intitialize plainText\n";
      str +=  "   intitialize gridText to cipherText plus password\n";
      str +=  "   \n";
      str +=  "   initialize columns to password's size\n";
      str +=  "   initialize rows to gridText's size\n";
      str +=  "   \n";
      str +=  "   set row to zero\n";
      str +=  "   set col to zero\n";
      str +=  "   set colStart to zero\n";
      str +=  "   set colEnd to columns size minus one\n";
      str +=  "   \n";
      str +=  "   while counter is less than size of gridText starting from 0, loop through gridText characters\n";
      str +=  "       if the current gridText character is valid\n";
      str +=  "           set current grid coordinates to the gridText character\n";
      str +=  "   \n";
      str +=  "           increment col by one\n";
      str +=  "   \n";
      str +=  "           if col is greater than colEnd\n";
      str +=  "               set col to zero\n";
      str +=  "               increment row\n";
      str +=  "   \n";
      str +=  "   set row back to 0\n";
      str +=  "   set col back to 0\n";
      str +=  "   initialize direction to 'forward'\n";
      str +=  "   \n";
      str +=  "   while counter is less than gridText size starting from zero, increment through the grid\n";
      str +=  "       if direction equals 'forward'\n";
      str +=  "           add the value of the current grid coordinates to plainText\n";
      str +=  "           increment col by one\n";
      str +=  "   \n";
      str +=  "           if col is greater than colEnd\n";
      str +=  "               set col to colEnd\n";
      str +=  "               increment row by one\n";
      str +=  "               change direction to 'backward'\n";
      str +=  "   \n";
      str +=  "       if direction equals 'backward'\n";
      str +=  "           add the value of the current grid coordinates to plainText\n";
      str +=  "           decrement col by one\n";
      str +=  "   \n";
      str +=  "           if col is less than colStart\n";
      str +=  "               set col to colStart\n";
      str +=  "               increment row by one\n";
      str +=  "               change direction to 'forward'\n";
      str +=  "   \n";
      str +=  "   return the substring of plainText up until were it matches the password\n";

      return str;
   }

   /**********************************************************
   * ENCRYPT
   * will create a two dimensional grid using the password size
   * for the row size and the plaintext + password size for the columns. Then,
   * the characters of the plaintext + password text will be added into the grid
   * one by one. After, the characters in the grid will be appended to the ciphertext
   * one by one in a zig zag pattern from the top left of the grid all the way to the
   * end of it. The cipherText will then be returned.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText;
	string gridText = plainText + password;

      //create two dimensional grid
      int cols = password.size();
      int rows = gridText.size();
      char grid[rows][cols];

      //add plaintext + password into grid
      int row = 0;
      int col = 0;
      int colStart = 0;
      int colEnd = cols - 1;

      for (int i = 0; i < gridText.size(); i++) {
         if (gridText[i]) {
             grid[row][col] = gridText[i];

         	 col++;

		 	 if (col > colEnd) {
			 	 col = 0;
			 	 row++;
		 	 }
         }
      }

      //Read grid into ciphertext using zig zag pattern
      row = 0;
      col = 0;
      string direction = "forward";
      
      for (int i = 0; i < gridText.size(); i++) {         
         if (direction == "forward") {
            cipherText += grid[row][col];
            col++;

            if(col > colEnd) {
			   col = colEnd;
               row++;
               direction = "backward";
            }
         }

         if (direction == "backward") {
            cipherText += grid[row][col];
            col--;

            if(col < colStart) {
			   col = colStart;
               row++;
               direction = "forward";
            }
         }
      }

      return cipherText;
   }

   /**********************************************************
   * DECRYPT
   * the ciphertext will be added into the same grid
   * in reverse and the reverse of the pattern (minus the size of the password)
   * will be used to derive the original plaintext.
   **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText;
	   string gridText = cipherText + password;
	   int plainSize = plainText.size() - password.size();

      //create two dimensional grid
      int cols = password.size();
      int rows = gridText.size();
      char grid[rows][cols];

      //add cipherText + password into grid
      int row = 0;
      int col = 0;
      int colStart = 0;
      int colEnd = cols - 1;

      for (int i = 0; i < gridText.size(); i++) {
         if (gridText[i]) {
             grid[row][col] = gridText[i];

         	 col++;

		 	 if (col > colEnd) {
			 	 col = 0;
			 	 row++;
		 	 }
         }
      }

      //Read grid into plainText using zig zag pattern
      row = 0;
      col = 0;
      string direction = "forward";
      
      for (int i = 0; i < gridText.size(); i++) {         
         if (direction == "forward") {
            plainText += grid[row][col];
            col++;

            if(col > colEnd) {
			   col = colEnd;
               row++;
               direction = "backward";
            }
         }

         if (direction == "backward") {
            plainText += grid[row][col];
            col--;

            if(col < colStart) {
			   col = colStart;
               row++;
               direction = "forward";
            }
         }
      }

      return plainText.substr(0, plainText.find(password));
   }
};

#endif // CIPHER02_H