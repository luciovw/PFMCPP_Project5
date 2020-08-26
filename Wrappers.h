#pragma once

struct CodingLanguage;
struct ElectricGuitar;
struct AudioApplication;
struct Computer;
struct GuitarRoom;

struct CodingLanguageWrapper
{
    CodingLanguageWrapper(CodingLanguage* ptr);
    ~CodingLanguageWrapper();
    CodingLanguage* ptr2CodingLanguage = nullptr;
};

struct ElectricGuitarWrapper
{
    ElectricGuitarWrapper(ElectricGuitar* ptr);
    ~ElectricGuitarWrapper();
    ElectricGuitar* ptr2ElectricGuitar = nullptr;
};

struct AudioApplicationWrapper
{
    AudioApplicationWrapper(AudioApplication* ptr);
    ~AudioApplicationWrapper();
    AudioApplication* ptr2AudioApplication = nullptr;
};

struct ComputerWrapper
{
    ComputerWrapper(Computer* ptr);
    ~ComputerWrapper();
    Computer* ptr2Computer = nullptr;
};

struct GuitarRoomWrapper
{
    GuitarRoomWrapper(GuitarRoom* ptr);
    ~GuitarRoomWrapper();
    GuitarRoom* ptr2GuitarRoom = nullptr;
};

