#include <string>
#include <iostream>
#include <locale> 

#include "Cipher.h"
using namespace std;

int getOffsetAscii(int,bool);

bool isExceedBounds(int);

Cipher::Cipher()
{
  _plaintxt = "";
  _rot = 0;
}

Cipher::Cipher( std::string plaintxt, int rot )
{
  _plaintxt = plaintxt;
  _rot = rot;
}

void Cipher::setPlaintxt( std::string plaintxt )
{
  _plaintxt = plaintxt;
}

void Cipher::setRot( int rot )
{
  _rot = rot;
}

std::string Cipher::getCiphertxt()
{
  // generate ciphertxt of _plaintxt
  // by transposing the character values by _rot
  
  // ASCII:
  // Uppercase: 65 - 90
  // Lowercase: 97 - 122
  
  const char * ptrPlaintxt = _plaintxt.c_str();
  std::string ciphertxt = "";
  
  while( *ptrPlaintxt != '\0' ){
    int rotatedVal = _getRotatedVal( int(*ptrPlaintxt) );
    
    char rotatedLetter = char( rotatedVal );
    
    ciphertxt.push_back( rotatedLetter );
    
    ptrPlaintxt++;
  }
  return ciphertxt;
}

int Cipher::_getRotatedVal( int initVal )
{
  bool isUppercase = initVal >= 65 && initVal <= 90;
  int offsetRot = 0;
  
  offsetRot = getOffsetAscii(initVal, isUppercase);
  
  int tmpRot = offsetRot + _rot;
    
  if( isExceedBounds( tmpRot ) ){
    if( tmpRot >= 0 ){
      tmpRot -= 26;
    }else{
      tmpRot += 26;
    }
  }
  
  if( isUppercase ){
    return tmpRot + 65;
  }
  
  return tmpRot + 97;
  
}

int getOffsetAscii( int val, bool isUpper ){
  if( isUpper ){
    return val - 65;
  }
  return val - 97;
}

bool isExceedBounds( int val ){
  return val < 0 || val > 25;
}
