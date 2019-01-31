#include <string>

using namespace std;

#ifndef _CIPHER_H_
#define _CIPHER_H_

class Cipher
{
  private:
    std::string _plaintxt;
    
    int _rot;    
    
    int _getRotatedVal( int );
public:
    Cipher();
  
    Cipher( std::string, int );
    
    void setPlaintxt( std::string );
    
    void setRot( int );
    
    std::string getCiphertxt();

};

#endif // _CIPHER_H_
