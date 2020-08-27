#include "AudioApplication.h"
#include <iostream>

AudioApplication::AudioApplication(float setDefaultRatio)
{
    initRatio = setDefaultRatio;
}

AudioApplication::~AudioApplication()
{
    std::cout<< "Closing Audio Application" << std::endl;
}

float AudioApplication::compress(float input, float ratio, float threshold)
{
    if (input > threshold)
    {
        std::cout << "Signal Compressed" << std::endl;
        return input * (0.1f * ratio);
    }
    return input;
}

float AudioApplication::reverberate(float input, float roomSize)
{
    float delayTimeMS = 10.0f * roomSize;
    return input * delayTimeMS;
}

float AudioApplication::semitoneTranspose(float input, int transposeVal)
{
    std::cout << "Signal Transposed" << std::endl;
    return input * transposeVal;
}

void AudioApplication::runAudio (float signal, int bufferSize)
{
    for (int i = 0; i < bufferSize; ++i)
    {
        compress(signal, 3, -10);
    }
    std::cout << "Compressed " << bufferSize << " samples of " << signal << std::endl;
}
