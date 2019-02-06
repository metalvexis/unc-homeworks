#include <iostream>
#include <cmath>
#include <string>
#include "BitSwapCipher.h";
using namespace std;

void testCipher(int k1, int k2, char * ptxt);

int main(int argc, char **argv)
{
  // test declared variable as parameter
  char * testStr = "DOG";
  testCipher(2, 5, testStr);
  
  // test declared inline value
  testCipher(2, 5, "PROGRAM");
  
  // test blank
  testCipher(2, 5, "");
  
  // test space
  testCipher(2, 5, " ");
  
  // test invalid keys
  testCipher(6, -1, "INVALID KEYS");
  
  // test spaces in between
  testCipher(1, 2, "JAMES PAULO");
  
  // test other keys
  testCipher(3, 4, "JAMES PAULO");
  
  // test same key pairs but swapped
  testCipher(3, 5, "JAMES PAULO");
  testCipher(5, 3, "JAMES PAULO");
  
	return 0;
}

void testCipher(int k1, int k2, char * ptxt){
  cout << "EncryptKeys: "<< k1 << " , " << k2 << endl;
  
  BitSwapCipher bitswap;
    
  bitswap.setEncryptionKey(k1, k2);
  
  
  std::string swapped1 = bitswap.encryptedText(ptxt);
  
  cout << "ENCRYPT: " << ptxt << " => " << swapped1;
  
  cout << endl;
  
  std::string reSwapped1 = bitswap.decryptedText(swapped1);
  
  cout << "DECRYPT: " << swapped1 << " => " << reSwapped1;
  cout << endl << endl;
}
