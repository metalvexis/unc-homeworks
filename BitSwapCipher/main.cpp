#include <iostream>
#include <cmath>
#include <string>
#include "BitSwapCipher.h";
using namespace std;

void binaryCountDown( int, bool*, int, int );
void getBinaryString( int, std::string&, int );
bool * toBinary( int );

void swapBit( int, int, bool* );

int main(int argc, char **argv)
{
  try{
    BitSwapCipher bitswap;
    
    bitswap.setEncryptionKey(2,5);
    
    char * testStr1 = "DOG";
    char * testStr2 = "PROGRAM";
    
    std::string swapped1 = bitswap.encryptedText(testStr1);
    std::string swapped2 = bitswap.encryptedText(testStr2);
    
    cout << testStr1 << " ==> " << swapped1;
    cout << endl;
    cout << testStr2 << " ==> " << swapped2;
    
    cout << endl;
    cout << endl;
    
    std::string reSwapped1 = bitswap.decryptedText(swapped1);
    std::string reSwapped2 = bitswap.decryptedText(swapped2);
    
    cout << swapped1 << " ==> " << reSwapped1;
    cout << endl;
    cout << swapped2 << " ==> " << reSwapped2;
    
    
  }catch( const char * err ){
    cout << err;
  }
  
	return 0;
}



void binaryCountDown( int decimalVal, bool* bits, int bitOffset, int recursionVal ){  
  
  if( recursionVal%2 != 0 && recursionVal > 1 ) throw "Odd integer"; // guard for odd #s
  
  if( recursionVal <= decimalVal ) {
    decimalVal -= recursionVal;
    bits[bitOffset] = 1;
  }
  
  bitOffset += 1;
  recursionVal /= 2;
  
  if( recursionVal>=1 ){
    binaryCountDown( decimalVal, bits, bitOffset, recursionVal );
  }
}

bool * toBinary( int decimalVal ){
  static bool bits []  = { 0, 0, 0, 0, 0 };
  
  binaryCountDown( decimalVal, bits, 0, 16 );
  
  return bits;
}

void swapBit(int p1, int p2, bool * bits){
  bool * tmp = bits+p1;
  bits+p2;
}