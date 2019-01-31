#include <stdio.h>
#include <string>
#include <iostream>
#include "Cipher.h"
using namespace std;

int main(int argc, char **argv)
{
  std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string lower = "abcdefghijklmnopqrstuvwxyz";
  
  Cipher cipher( upper, 1 );
  
  Cipher cipher2( upper, -1 );
  
  Cipher cipher3( lower, 1 );
  
  Cipher cipher4( lower, -1 );
  
  Cipher cipher5( upper, 26 );
  
  Cipher cipher6( upper, -26 );
  
  Cipher cipher7( lower, 26 );
  
  Cipher cipher8( lower, -26 );
  
  cout << "Plaintext (uppercase): " <<  upper << endl;
  cout << "Plaintext (lowercase): " <<  lower << endl;
  
  cout << cipher.getCiphertxt() << endl;
  cout << cipher2.getCiphertxt() << endl;
  cout << cipher3.getCiphertxt() << endl;
  cout << cipher4.getCiphertxt() << endl;
  cout << cipher5.getCiphertxt() << endl;
  cout << cipher6.getCiphertxt() << endl;
  cout << cipher7.getCiphertxt() << endl;
  cout << cipher8.getCiphertxt() << endl;
  
  return 0;
}
