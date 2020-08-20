/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */




#include <iostream>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */
struct CodingLanguage
{
    int numDataTypes = 7;
    int numFunctionTypes = 3;
    int numOperatorTypes = 6;
    int numPunctuationTypes = 5;
    int compilerBit_Sec = 1000000;

    float compileDCode = 0.0f;
    CodingLanguage(int setCompilerBit_Sec);
    ~CodingLanguage();

    int createIntFunction(int variable1, int variable2);

    float createFloatFunction(float variable1, float variable2);

    void compileCode(float code);

    void addTwo(float initialValue, int timesToAddTwo);
    JUCE_LEAK_DETECTOR(CodingLanguage)
};

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

struct CodingLanguageWrapper
{
    CodingLanguageWrapper(CodingLanguage* ptr) : ptr2CodingLanguage( ptr ){}
    ~CodingLanguageWrapper()
    {
        delete ptr2CodingLanguage;
    }
    CodingLanguage* ptr2CodingLanguage = nullptr;
};

/*
 copied UDT 2:
 */

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
    JUCE_LEAK_DETECTOR(ElectricGuitar)
};

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

struct ElectricGuitarWrapper
{
    ElectricGuitarWrapper(ElectricGuitar* ptr) : ptr2ElectricGuitar( ptr ){}
    ~ElectricGuitarWrapper()
    {
        delete ptr2ElectricGuitar;
    }
    ElectricGuitar* ptr2ElectricGuitar = nullptr;
};

/*
 copied UDT 3:
 */
struct AudioApplication
{
    float initRatio = 5.5f;
    float initThreshold = -19.5f;
    float initDecayTime = 3.4f;
    float initPreDelay = 10.2f;
    int initTranspose = -7;
    AudioApplication(float setDefaultRatio);
    ~AudioApplication();

    float compress(float input, float ratio, float threshold);
    float reverberate(float input, float roomSize);
    float semitoneTranspose(float input, int transposeVal);
    void runAudio (float signal, int bufferSize);

    JUCE_LEAK_DETECTOR(AudioApplication)
};

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
    if (input>threshold)
    {
        std::cout << "Signal Compressed" << std::endl;
        return input * (0.1f*ratio);
    } 
    else
    {
        return input;
    }
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

struct AudioApplicationWrapper
{
    AudioApplicationWrapper(AudioApplication* ptr) : ptr2AudioApplication( ptr ){}
    ~AudioApplicationWrapper()
    {
        delete ptr2AudioApplication;
    }
    AudioApplication* ptr2AudioApplication = nullptr;
};

/*
 new UDT 4:
 with 2 member functions
 */
struct Computer
{
    CodingLanguage language1{5000};
    Computer();
    ~Computer();

    void changeNumDataTypes(int newNumDataTypes);
    void changeNumOperatorTypes(int newNumOperatorTypes);

    void changeNumDataTypesThis(int numDataTypes);
    void changeNumOperatorTypesThis(int numOperatorTypes);

    JUCE_LEAK_DETECTOR(Computer)
};

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

struct ComputerWrapper
{
    ComputerWrapper(Computer* ptr) : ptr2Computer( ptr ){}
    ~ComputerWrapper()
    {
        delete ptr2Computer;
    }
    Computer* ptr2Computer = nullptr;
};

/*
 new UDT 5:
 with 2 member functions
 */
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

    JUCE_LEAK_DETECTOR(GuitarRoom)
};

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

struct GuitarRoomWrapper
{
    GuitarRoomWrapper(GuitarRoom* ptr) : ptr2GuitarRoom( ptr ){}
    ~GuitarRoomWrapper()
    {
        delete ptr2GuitarRoom;
    }
    GuitarRoom* ptr2GuitarRoom = nullptr;
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{ 

    //AxeWrapper axWrapper( new Axe() );

    CodingLanguageWrapper LL( new CodingLanguage(5) );
    LL.ptr2CodingLanguage->createFloatFunction(10.5f, 30.7f);

    ElectricGuitarWrapper strat( new ElectricGuitar (0) );
    strat.ptr2ElectricGuitar->warmTone(220);
    strat.ptr2ElectricGuitar->amplifyStringVibration(4, 220);

    AudioApplicationWrapper compressor1( new AudioApplication (2) );
    std:: cout << compressor1.ptr2AudioApplication->compress(3.3f, 5.0f, -22.2f) << " = new signal value!" << std::endl;

    LL.ptr2CodingLanguage->addTwo(10, 5);

    strat.ptr2ElectricGuitar->tuneString(500, 600);
    strat.ptr2ElectricGuitar->tuneString(600, 500);
    strat.ptr2ElectricGuitar->tuneString(600, 600);

    AudioApplicationWrapper audioProcessor( new AudioApplication (7) );
    audioProcessor.ptr2AudioApplication->runAudio(10, 4);

    //New Additions to main
    std::cout << "\nnew additions to main: " << std::endl;

    ComputerWrapper compy ( new Computer() );
    compy.ptr2Computer->changeNumDataTypes(4);
    compy.ptr2Computer->changeNumOperatorTypes(9);

    GuitarRoomWrapper guitarAndPedal ( new GuitarRoom () );
    guitarAndPedal.ptr2GuitarRoom->modifyPickups(3);
    guitarAndPedal.ptr2GuitarRoom->turnRatioKnob(6);

    //std::cout statements to replicate
    std::cout << "\ncout statements to replicate: " << std::endl;

    std::cout << "New number of data types: " << compy.ptr2Computer->language1.numDataTypes << std::endl;

    std::cout << "New number of operator types: " << compy.ptr2Computer->language1.numOperatorTypes << std::endl;

    std::cout << "New number of guitar Pickups: " << guitarAndPedal.ptr2GuitarRoom->eGuitar.numPickUps << std::endl;

    std::cout << "New compression ratio: " << guitarAndPedal.ptr2GuitarRoom->guitarPedal.initRatio << std::endl;

    //replications with this
    std::cout <<  "\nstatement replications using this->: " << std::endl;

    compy.ptr2Computer->changeNumDataTypesThis(4);
    compy.ptr2Computer->changeNumOperatorTypesThis(9);

    guitarAndPedal.ptr2GuitarRoom->modifyPickupsThis(3);
    guitarAndPedal.ptr2GuitarRoom->turnRatioKnobThis(6);

    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
