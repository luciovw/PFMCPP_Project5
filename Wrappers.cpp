#include "AudioApplication.h"
#include "ElectricGuitar.h"
#include "CodingLanguage.h"
#include "GuitarRoom.h"
#include"Computer.h"
#include "Wrappers.h"

CodingLanguageWrapper::CodingLanguageWrapper(CodingLanguage* ptr) : ptr2CodingLanguage( ptr ){}

CodingLanguageWrapper::~CodingLanguageWrapper()
{
    delete ptr2CodingLanguage;
}
//==================================================================

ElectricGuitarWrapper::ElectricGuitarWrapper(ElectricGuitar* ptr) : ptr2ElectricGuitar( ptr ){}

ElectricGuitarWrapper::~ElectricGuitarWrapper()
{
    delete ptr2ElectricGuitar;
}
//==================================================================

AudioApplicationWrapper::AudioApplicationWrapper(AudioApplication* ptr) : ptr2AudioApplication( ptr ){}

AudioApplicationWrapper::~AudioApplicationWrapper()
{
    delete ptr2AudioApplication;
}
//==================================================================

ComputerWrapper::ComputerWrapper(Computer* ptr) : ptr2Computer( ptr ){}

ComputerWrapper::~ComputerWrapper()
{
    delete ptr2Computer;
}
//==================================================================

GuitarRoomWrapper::GuitarRoomWrapper(GuitarRoom* ptr) : ptr2GuitarRoom( ptr ){}
    
GuitarRoomWrapper::~GuitarRoomWrapper()
{
    delete ptr2GuitarRoom;
}

