/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

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

    void changeNumDataTypesThis(int numDataTypes);
    void changeNumOperatorTypesThis(int numOperatorTypes);
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
    this -> language1.numDataTypes = numDataTypes;
    std::cout << "New number of data types: " << language1.numDataTypes << std::endl;
}

void Computer::changeNumOperatorTypesThis(int numOperatorTypes)
{
    this -> language1.numOperatorTypes = numOperatorTypes;
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

    void modifyPickupsThis(int numPickUps);
    void turnRatioKnobThis(int ratio);
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
    this -> eGuitar.numPickUps = numPickUps;
    std::cout << "New number of guitar Pickups: " << eGuitar.numPickUps << std::endl;
}

void GuitarRoom::turnRatioKnobThis(int ratio)
{
    this->guitarPedal.initRatio = ratio;
    std::cout << "New compression ratio: " << guitarPedal.initRatio << std::endl;
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

    compy.changeNumDataTypesThis(6);
    compy.changeNumOperatorTypesThis(11);

    guitarAndPedal.modifyPickupsThis(5);
    guitarAndPedal.turnRatioKnobThis(8);

    std::cout << "good to go!" << std::endl;
}
