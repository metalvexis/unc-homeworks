#include <iostream>
#include <string>
#include "Rectangle.h"

using namespace std;

void displayDimensions( std::string, Rectangle );

int main()
{
    Rectangle r1(10, 5);
    
    displayDimensions("1", r1);
    
    r1.plot();
    
    Rectangle r2(5, 7);
    
    displayDimensions("2", r2);
    r2.plot();
    
    Rectangle r3;
    
    displayDimensions("3", r3);
    r3.plot();
    

	return 0;
}

void displayDimensions(std::string testCount, Rectangle r){
    cout << "Test " << testCount << endl;
    cout << "-------------------------------" << endl;
    cout << "Length = " << r.length() << " ";
    cout << "Width = " << r.width() << " ";
    cout << "Area = " << r.area() << " " << endl;
    cout << "-------------------------------" << endl;
}