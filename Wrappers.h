struct CodingLanguageWrapper
{
    CodingLanguageWrapper(CodingLanguage* ptr) : ptr2CodingLanguage( ptr ){}
    ~CodingLanguageWrapper()
    {
        delete ptr2CodingLanguage;
    }
    CodingLanguage* ptr2CodingLanguage = nullptr;
};

struct ElectricGuitarWrapper
{
    ElectricGuitarWrapper(ElectricGuitar* ptr) : ptr2ElectricGuitar( ptr ){}
    ~ElectricGuitarWrapper()
    {
        delete ptr2ElectricGuitar;
    }
    ElectricGuitar* ptr2ElectricGuitar = nullptr;
};

struct AudioApplicationWrapper
{
    AudioApplicationWrapper(AudioApplication* ptr) : ptr2AudioApplication( ptr ){}
    ~AudioApplicationWrapper()
    {
        delete ptr2AudioApplication;
    }
    AudioApplication* ptr2AudioApplication = nullptr;
};

struct ComputerWrapper
{
    ComputerWrapper(Computer* ptr) : ptr2Computer( ptr ){}
    ~ComputerWrapper()
    {
        delete ptr2Computer;
    }
    Computer* ptr2Computer = nullptr;
};

struct GuitarRoomWrapper
{
    GuitarRoomWrapper(GuitarRoom* ptr) : ptr2GuitarRoom( ptr ){}
    ~GuitarRoomWrapper()
    {
        delete ptr2GuitarRoom;
    }
    GuitarRoom* ptr2GuitarRoom = nullptr;
};

