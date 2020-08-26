#include "ElectricGuitar.h"
#include <iostream>

ElectricGuitar::ElectricGuitar(int numBrokenStrings)
{
    numStrings-=numBrokenStrings;
}

ElectricGuitar::~ElectricGuitar()
{
    std::cout << "Destructing a ElectricGuitar Object" << std::endl;
}

float ElectricGuitar::amplifyStringVibration(int stringNum, float stringFreq)
{
    float amplifiedNote = stringNum * stringFreq;
    std::cout << "Note to be amplified: " << amplifiedNote << std::endl;
    return amplifiedNote;
}
float ElectricGuitar::warmTone (float noteInfo)
{
    float highshelf = -3.0f;
    std::cout << "Tone is now warmer!" << std::endl;
    return noteInfo * highshelf;
}

float ElectricGuitar::brightTone (float noteInfo)
{
    float highshelf = 3.0f;
    return noteInfo * highshelf;
}

void ElectricGuitar::tuneString(int currentNoteInfo, int targetNote)
{
    if (currentNoteInfo < targetNote)
    {
        std::cout << "You were flat! ";
        while (currentNoteInfo < targetNote)
        {
            ++currentNoteInfo;
        }
        std::cout << "Now you're in tune." << std::endl;
    } 
    else if (currentNoteInfo > targetNote)
    {
        std::cout << "You were sharp! ";
        while (currentNoteInfo > targetNote)
        {
            currentNoteInfo -= 1;
        }
        std::cout << "Now you're in tune." << std::endl;
    } 
    else if (currentNoteInfo == targetNote)
    {
        std::cout << "You're already in tune!!" << std::endl;
    }
}
