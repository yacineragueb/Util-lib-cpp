#pragma once
#include <iostream>
#include <string>
#include "../date/clsDate.h" // You can get this lib from https://github.com/yacineragueb/Date-lib-cpp

class clsUtil
{
public:
    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4,
        MixChars = 5
    };

    static void Srand() {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
        case enCharType::Digit:
            return char(RandomNumber(48, 57));
        case enCharType::MixChars:
            return char(RandomNumber(33, 122));
        }

        return '\0';
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string word = "";

        for (int i = 1; i <= Length; i++)
        {
            word = word + GetRandomCharacter(CharType);
        }

        return word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string key = "";

        key = GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4) + "-";
        key = key + GenerateWord(CharType, 4);

        return key;
    }

    static void GenerateKeys(int NumberOfKeys, enCharType CharType)
    {
        for (int i = 0; i < NumberOfKeys; i++)
        {
            cout << "Key [" << i + 1 << "] : " << GenerateKey(CharType) << endl;
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void ShuffleArray(int array[100], short arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;

            Swap(array[index1], array[index2]);
        }
    }

    static void ShuffleArray(string array[100], short arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;

            Swap(array[index1], array[index2]);
        }
    }

    static void FillArrayWithRandomNumbers(int array[100], short arrLength, int From, int To) {
        for (int i = 0; i < arrLength; i++) {
            array[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string array[100], short arrLength, enCharType CharType, short Length) {
        for (int i = 0; i < arrLength; i++) {
            array[i] = GenerateWord(CharType, Length);
        }
    }

    static void FillArrayWithRandomKeys(string array[100], short arrLength, enCharType CharType) {
        for (int i = 0; i < arrLength; i++) {
            array[i] = GenerateKey(CharType);
        }
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (short i = 0; i < NumberOfTabs; i++)
        {
            t += "\t";
        }

        return t;
    }

    static string EncryptText(string OrignalName, short EncryptionKey)
    {
        for (int i = 0; i < OrignalName.length(); i++)
        {
            OrignalName[i] = char(int(OrignalName[i]) + EncryptionKey);
        }

        return OrignalName;
    }

    static string DecryptText(string encyptionName, short EncryptionKey)
    {
        for (int i = 0; i < encyptionName.length(); i++)
        {
            encyptionName[i] = char(int(encyptionName[i]) - EncryptionKey);
        }

        return encyptionName;
    }
};

