/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Substitution : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Christopher Van Kammen"; }
   virtual std::string getCipherName()  { return "Substitution cipher"; }
   virtual std::string getEncryptAuth() { return "Christopher Van Kammen"; }
   virtual std::string getDecryptAuth() { return "Christopher Van Kammen"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Simon Singh. (n.d.). Crypto. Practical Cryptography.\n"
                         "http://practicalcryptography.com/ciphers/classical-era/simple-substitution/");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "";

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      int count = 0;
      std::string cipherText;
      for (int i = plainText.length() - 1; i >= 0; i--)
      {
          cipherText += substitution.find(plainText[count])->second;
          count++;
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText;
      int count = 0;
      for (int i = cipherText.length() - 1; i >= 0; i--)
      {
        plainText += substitutionReverse.find(cipherText[count])->second;
        count++;
      }
      return plainText;
   }

private:
   std::map<char, char> substitution = {
              { 'a', 'q' },
              { 'b', 'w' },
              { 'c', 'e' },
              { 'd', 'r' },
              { 'e', 't' },
              { 'f', 'y' },
              { 'g', 'u' },
              { 'h', 'i' },
              { 'i', 'o' },
              { 'j', 'p' },
              { 'k', '[' },
              { 'l', ']' },
              { 'm', 'a' },
              { 'n', 's' },
              { 'o', 'd' },
              { 'p', 'f' },
              { 'q', 'g' },
              { 'r', 'h' },
              { 's', 'j' },
              { 't', 'k' },
              { 'u', 'l' },
              { 'v', ';' },
              { 'w', '1' },
              { 'x', 'z' },
              { 'y', 'x' },
              { 'z', 'c' },
              { 'A', 'v' },
              { 'B', 'b' },
              { 'C', 'n' },
              { 'D', 'm' },
              { 'E', 'm' },
              { 'F', ',' },
              { 'G', '.' },
              { 'H', '/' },
              { 'I', 'Q' },
              { 'J', 'W' },
              { 'K', 'E' },
              { 'L', 'R' },
              { 'M', 'T' },
              { 'N', 'T' },
              { 'O', 'Y' },
              { 'P', 'U' },
              { 'Q', 'I' },
              { 'R', 'O' },
              { 'S', 'P' },
              { 'T', '{' },
              { 'U', '}' },
              { 'V', '|' },
              { 'W', 'A' },
              { 'X', 'S' },
              { 'Y', 'D' },
              { 'Z', 'F' },
              { '0', 'G' },
              { '1', 'H' },
              { '2', 'J' },
              { '3', 'K' },
              { '4', 'L' },
              { '5', 'Z' },
              { '6', 'X' },
              { '7', 'C' },
              { '8', 'V' },
              { '9', 'B' },
              { '!', 'N' },
              { '@', 'M' },
              { '#', '<' },
              { '$', '>' },
              { '%', '?' },
              { '^', '2' },
              { '&', '3' },
              { '*', '4' },
              { '(', '5' },
              { ')', '6' },
              { '-', '7' },
              { '_', '8' },
              { '=', '9' },
              { '+', '0' },
              { '[', '-' },
              { '{', '_' },
              { ']', '+' },
              { '}', '=' },
              { '|', '!' },
              { ';', '@' },
              { ':', '#' },
              { '\'','$' },
              { '<', '^' },
              { ',', '&' },
              { '>', '*' },
              { '/', ')' },
              { '?', '`' },
              { ' ', '~' },
              { '\n', '('},
              { '\t', '%'}
   };
   
   std::map<char, char> substitutionReverse = {
              { 'q', 'a' },
              { 'w', 'b' },
              { 'e', 'c' },
              { 'r', 'd' },
              { 't', 'e' },
              { 'y', 'f' },
              { 'u', 'g' },
              { 'i', 'h' },
              { 'o', 'i' },
              { 'p', 'j' },
              { '[', 'k' },
              { ']', 'l' },
              { 'a', 'm' },
              { 's', 'n' },
              { 'd', 'o' },
              { 'f', 'p' },
              { 'g', 'q' },
              { 'h', 'r' },
              { 'j', 's' },
              { 'k', 't' },
              { 'l', 'u' },
              { ';', 'v' },
              { '1', 'w' },
              { 'z', 'x' },
              { 'x', 'y' },
              { 'c', 'z' },
              { 'v', 'A' },
              { 'b', 'B' },
              { 'n', 'C' },
              { 'm', 'D' },
              { 'm', 'E' },
              { ',', 'F' },
              { '.', 'G' },
              { '/', 'H' },
              { 'Q', 'I' },
              { 'W', 'J' },
              { 'E', 'K' },
              { 'R', 'L' },
              { 'T', 'M' },
              { 'T', 'N' },
              { 'Y', 'O' },
              { 'U', 'P' },
              { 'I', 'Q' },
              { 'O', 'R' },
              { 'P', 'S' },
              { '{', 'T' },
              { '}', 'U' },
              { '|', 'V' },
              { 'A', 'W' },
              { 'S', 'X' },
              { 'D', 'Y' },
              { 'F', 'Z' },
              { 'G', '0' },
              { 'H', '1' },
              { 'J', '2' },
              { 'K', '3' },
              { 'L', '4' },
              { 'Z', '5' },
              { 'X', '6' },
              { 'C', '7' },
              { 'V', '8' },
              { 'B', '9' },
              { 'N', '!' },
              { 'M', '@' },
              { '<', '#' },
              { '>', '$' },
              { '?', '%' },
              { '2', '^' },
              { '3', '&' },
              { '4', '*' },
              { '5', '(' },
              { '6', ')' },
              { '7', '-' },
              { '8', '_' },
              { '9', '=' },
              { '0', '+' },
              { '-', '[' },
              { '_', '{' },
              { '+', ']' },
              { '=', '}' },
              { '!', '|' },
              { '@', ';' },
              { '#', ':' },
              { '$', '\''},
              { '^', '<' },
              { '&', ',' },
              { '*', '>' },
              { ')', '/' },
              { '`', '?' },
              { '~', ' ' },
              {'(', '\n' },
              {'%', '\t' }
   };
};

#endif // SUBSTITUTION_H