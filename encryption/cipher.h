/********************************************************************
* Header:
*    This is the base Cipher Class.
********************************************************************/
#ifndef CIPHER_H
#define CIPHER_H

/********************************************************************
 * CLASS CIPHER
 *******************************************************************/
class Cipher
{
public:
   virtual std::string getCipherName() = 0;
   virtual std::string getCipherCitation() = 0;
   virtual std::string getPseudoAuth() = 0;
   virtual std::string getEncryptAuth() = 0;
   virtual std::string getDecryptAuth() = 0;
   virtual std::string getPseudocode() = 0;

   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password) = 0;
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password) = 0;
};

#endif //CIPHER_H