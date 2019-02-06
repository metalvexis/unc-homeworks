#include <utility>
#include <string>

#ifndef _BITSWAPCIPHER_
#define _BITSWAPCIPHER_

class BitSwapCipher
{
private:
  // encryption key pairs
  std::pair<int, int> _keys;


  // accepts an integer and returns the binary string equivalent.
  std::string toBinary(int);
  
  // accepts a binary string and returns the equivalent decimal value
  int toDecimal(std::string);
  
  // accepts binary in string format and swaps bits according to encryption keys
  void bitSwap(std::string&);

  // accepts char to swap into another char
  char charSwap(char);
  
  // returns true if keys are between 0-4
  bool isKeyValid();
  
public:  
  BitSwapCipher(){ _keys.first = 0; _keys.second = 0; };
  
  BitSwapCipher(int k1, int k2){ setEncryptionKey(k1,k2); };
  
  void setEncryptionKey(int k1, int k2){ _keys.first = k1-1; _keys.second = k2-1; };
  
  // encrypts a string
  // This function returns an empty string if either the plaintext is blank or 
  // if the encryption key pair is not valid (encryption key is
  // valid only if each value of the pair is between 1 and 5).
  std::string encryptedText(char*);
  
  // reverse of the encryption process
  std::string decryptedText(std::string);

};

#endif // _BITSWAPCIPHER_
