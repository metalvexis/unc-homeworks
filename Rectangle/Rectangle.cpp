#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(){
    _length = 0;
    _width = 0;
}

Rectangle::Rectangle(int l, int w){
    _length = l;
    _width = w;
}

int Rectangle::length(){
    return _length;
}

int Rectangle::width(){
    return _width;
}

int Rectangle::area(){
    return _length * _width;
}

void Rectangle::plot(){
    
    if( area() == 0 ){
        cout << "No rectangle can be printed";
    }
    
    int maxWidth = _width;
    int maxLength = _length;
    
    for(int i=0; i < maxWidth; i++ ){
        
        bool isEdges = i == 0 || i == maxWidth-1;
        
        if( isEdges ){
            for(int _i=0; _i < maxLength; _i++ ){
                cout << "*";
            }
        }else{
            cout << "*";
            for(int _i=0; _i < maxLength-2; _i++ ){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }    
    cout << endl;
}