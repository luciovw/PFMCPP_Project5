#include "Computer.h"
#include <iostream>

void Computer::changeNumDataTypes(int newNumDataTypes)
{
    language1.numDataTypes = newNumDataTypes;
    std::cout << "New number of data types: " << language1.numDataTypes << std::endl;
}

void Computer::changeNumOperatorTypes(int newNumOperatorTypes)
{
    language1.numOperatorTypes = newNumOperatorTypes;
    std::cout << "New number of operator types: " << language1.numOperatorTypes << std::endl;
}

void Computer::changeNumDataTypesThis(int numDataTypes)
{
    this->language1.numDataTypes = numDataTypes;
    std::cout << "New number of data types: " << this->language1.numDataTypes << std::endl;
}

void Computer::changeNumOperatorTypesThis(int numOperatorTypes)
{
    this->language1.numOperatorTypes = numOperatorTypes;
    std::cout << "New number of operator types: " << this->language1.numOperatorTypes << std::endl;
}

Computer::Computer()
{
    //Default constructor
}

Computer::~Computer()
{
    std::cout << "Are you sure you want to shutdown?" << std::endl;
}
