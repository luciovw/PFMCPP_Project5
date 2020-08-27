#pragma once
struct ElectricGuitar
{
    int numStrings = 6;
    int numFrets = 20;
    int numPickUps = 2;
    int numPickupPositions = 5;
    int numKnobs = 3;
    int volumeKnobValue = 10;
    ElectricGuitar(int numBrokenStrings);
    ~ElectricGuitar();

    float amplifyStringVibration(int stringNum, float stringFreq);
    float warmTone (float noteInfo);
    float brightTone (float noteInfo);

    void tuneString(int currentNoteInfo, int targetNote);
    
};
