#include "CodingLanguage.h"
#include <iostream>

CodingLanguage::CodingLanguage(int setCompilerBit_Sec)
{
    compilerBit_Sec = setCompilerBit_Sec;
}

CodingLanguage::~CodingLanguage()
{
    std::cout << "Goodbye" << std::endl;
}

int CodingLanguage::createIntFunction(int variable1, int variable2)
{

    int add = variable1 + variable2;
    return add;
}

float CodingLanguage::createFloatFunction(float variable1, float variable2)
{
    float subtract = variable1 - variable2;
    std::cout << "Result: " << subtract << "\n";
    return subtract;
}

void CodingLanguage::compileCode(float code)
{
    int numOfThingsACompilerDoes = 1000000;
    compileDCode = code * numOfThingsACompilerDoes;
}

void CodingLanguage::addTwo(float initialValue, int timesToAddTwo)
{
    std::cout << "Starting value: " << initialValue << ". ";
    
    for (int i = 0; i < timesToAddTwo; ++i)
    {
        initialValue += 2;
    }

    std::cout << "2 added " << timesToAddTwo << " times. New Value = " << initialValue << std::endl;
}
