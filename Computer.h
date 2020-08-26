#pragma once
#include "CodingLanguage.h"

struct Computer
{
    CodingLanguage language1{5000};
    Computer();
    ~Computer();

    void changeNumDataTypes(int newNumDataTypes);
    void changeNumOperatorTypes(int newNumOperatorTypes);

    void changeNumDataTypesThis(int numDataTypes);
    void changeNumOperatorTypesThis(int numOperatorTypes);

};
