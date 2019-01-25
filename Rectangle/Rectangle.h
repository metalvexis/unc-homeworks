#include <string>

using namespace std;

#ifndef _RECTANGLE_
#define _RECTANGLE_


class Rectangle{
private:
    int _length;
    int _width;

public:
    Rectangle();
    Rectangle(int, int);
    int length();
    int width();
    int area();
    void plot();
    
};

#endif