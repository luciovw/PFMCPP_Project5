#include"GuitarRoom.h"
#include<iostream>

void GuitarRoom::modifyPickups(int newNumPickUps)
{
    eGuitar.numPickUps = newNumPickUps;
    std::cout << "New number of guitar Pickups: " << eGuitar.numPickUps << std::endl;
}

void GuitarRoom::turnRatioKnob(int newRatio)
{
    guitarPedal.initRatio = newRatio;
    std::cout << "New compression ratio: " << guitarPedal.initRatio << std::endl;
}

void GuitarRoom::modifyPickupsThis(int numPickUps)
{
    this->eGuitar.numPickUps = numPickUps;
    
    std::cout << "New number of guitar Pickups: " << this->eGuitar.numPickUps << std::endl;
}

void GuitarRoom::turnRatioKnobThis(int ratio)
{
    this->guitarPedal.initRatio = ratio;
    std::cout << "New compression ratio: " << this->guitarPedal.initRatio << std::endl;
}

GuitarRoom::GuitarRoom()
{
    eGuitar.volumeKnobValue = 10;
}

GuitarRoom::~GuitarRoom()
{
    eGuitar.volumeKnobValue = 0;
    std::cout << "That's enough for today, I guess." << std::endl;
}
