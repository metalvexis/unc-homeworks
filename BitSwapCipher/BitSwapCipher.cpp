#include "BitSwapCipher.h"
#include <cmath>
#include <utility>
#include <string>
#include <iostream>

using namespace std;


// accepts an integer and returns the binary string equivalent.
std::string BitSwapCipher::toBinary(int decimalVal){
  std::string binString = "";
  int maxPlaceValue = 16; // 5^2
  
  for( int binCount = maxPlaceValue; binCount>=1; binCount/=2 ){
    if(binCount<=decimalVal) {
      decimalVal-=binCount;
      binString.push_back('1');
    }
    else 
      binString.push_back('0');
  }
  
  return binString;
}
  
// accepts a binary string and returns the equivalent decimal value
int BitSwapCipher::toDecimal(std::string binString){
  int decimalVal = 0;
  for( int placeValue = 0; placeValue<=4; placeValue++ ){
    if( binString[ placeValue ] == '1' ){
      decimalVal += std::pow(2.0, 4 - placeValue);
    }
  }
  return decimalVal;
}

std::string BitSwapCipher::encryptedText(char * plaintxt){

  std::string ciphertxt = "";

  while(*plaintxt){
    ciphertxt.push_back( charSwap(*plaintxt) );
    
    plaintxt++;
  }
  
  return ciphertxt;
}

std::string BitSwapCipher::decryptedText(std::string ciphertxt){
  const char * plaintxt = ciphertxt.c_str();

  return encryptedText( const_cast<char*>(plaintxt));
}

void BitSwapCipher::bitSwap(std::string& binString){
  char tmpChar = binString.at(_keys.first);
  binString.at(_keys.first) = binString.at(_keys.second);
  binString.at(_keys.second) = tmpChar;
}

char BitSwapCipher::charSwap(char plainChar){
    int asciiValue = int(plainChar) - 65; // offset ascii values to use values 0-25
    std::string binString = toBinary(asciiValue);
    int decimalValue = 0;
    
//    cout << "PRE-SWAP " << binString << " == " << *plaintxt << "|" << decimalValue << endl; 

    bitSwap(binString);
    
    decimalValue = toDecimal(binString);
    
    if( decimalValue > 25 ){
      decimalValue = asciiValue;
    }
    
    char newChar = char(decimalValue + 65); // reverse offset to use ascii value

//    cout << "POST-SWAP " << binString << " == " << newChar << "|" << decimalValue << endl << endl;   

    return newChar;
}