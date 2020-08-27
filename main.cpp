/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include <iostream>

#include "LeakedObjectDetector.h"

#include "Computer.h"
#include "GuitarRoom.h"
#include "Wrappers.h"

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

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
