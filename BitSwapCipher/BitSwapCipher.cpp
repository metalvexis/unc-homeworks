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