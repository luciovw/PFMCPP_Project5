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
