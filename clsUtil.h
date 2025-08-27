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

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "Zero";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }
    }
};

