/*
Project 5: Part 1 / 4

 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

#include <iostream>

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

Computer::Computer()
{
    //Default constructor
}

Computer::~Computer()
{
    std::cout << "Are you sure you want to shutdown?" << std::endl;
}

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

GuitarRoom::GuitarRoom()
{
    eGuitar.volumeKnobValue = 0;
}

GuitarRoom::~GuitarRoom()
{
    eGuitar.volumeKnobValue = 0;
    std::cout << "That's enough for today, I guess." << std::endl;
}

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

    CodingLanguage LL(5);
    LL.createFloatFunction(10.5f, 30.7f);

    ElectricGuitar strat(0);
    strat.warmTone(220);
    strat.amplifyStringVibration(4, 220);

    AudioApplication compressor1(2);
    std:: cout << compressor1.compress(3.3f, 5.0f, -22.2f) << " = new signal value!" << std::endl;

    LL.addTwo(10, 5);

    strat.tuneString(500, 600);
    strat.tuneString(600, 500);
    strat.tuneString(600, 600);

    AudioApplication audioProcessor(7);
    audioProcessor.runAudio(10, 4);

    //New Additions to main

    Computer compy;
    compy.changeNumDataTypes(4);
    compy.changeNumOperatorTypes(9);

    GuitarRoom guitarAndPedal;
    guitarAndPedal.modifyPickups(3);
    guitarAndPedal.turnRatioKnob(6);

    std::cout << "good to go!" << std::endl;
}
