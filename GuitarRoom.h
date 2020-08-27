#pragma once
#include "ElectricGuitar.h"
#include "AudioApplication.h"

struct GuitarRoom
{
    ElectricGuitar eGuitar{1};
    AudioApplication guitarPedal{4};
    GuitarRoom();
    ~GuitarRoom();

    void modifyPickups(int newNumPickUps);
    void turnRatioKnob(int newRatio);

    void modifyPickupsThis(int numPickUps);
    void turnRatioKnobThis(int ratio);
    
};
