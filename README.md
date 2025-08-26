# 📚 clsUtil - Utility Library in C++

`clsUtil` is a lightweight C++ utility library that provides a collection of static helper functions for **random generation**, **array manipulation**, **swapping**, and **basic encryption/decryption**.  
It is designed to make repetitive programming tasks easier and more efficient.

This project is perfect for learning **Object-Oriented Programming (OOP)** in C++ and for building reusable libraries.

---

## 🚀 Features

- **Random Generation**
  - Generate random numbers within a range.
  - Generate random characters (`SmallLetter`, `CapitalLetter`, `SpecialCharacter`, `Digit`, or `MixChars`).
  - Generate random words and license-like keys.

- **Array Utilities**
  - Fill arrays with random numbers, words, or keys.
  - Shuffle arrays (`int[]` or `string[]`).

- **Swap Utilities**
  - Swap integers, doubles, strings, or custom `clsDate` objects.

- **Text Utilities**
  - Add tabs easily (`Tabs()`).
  - Encrypt and decrypt text with a simple shift key.

- **Key Generation**
  - Generate license-like keys (e.g., `ABCD-EFGH-IJKL-MNOP`).

---

## 💻 Example Usage
```cpp
#include <iostream>
#include "clsUtil.h"

int main() {
    clsUtil::Srand();
    std::cout << "Random Number: " << clsUtil::RandomNumber(1, 100) << std::endl;
    // Example output: 56

    std::string key = clsUtil::GenerateKey(clsUtil::enCharType::CapitalLetter);
    std::cout << "Generated Key: " << key << std::endl;
    // Example output: ABTZ-XRPL-QWMD-KJHF

    std::string text = "HelloWorld";
    std::string encrypted = clsUtil::EncryptText(text, 3);
    std::string decrypted = clsUtil::DecryptText(encrypted, 3);

    std::cout << "Original: " << text << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    int arr[100];
    clsUtil::FillArrayWithRandomNumbers(arr, 10, 1, 50);

    std::cout << "Before Shuffle: ";
    for (int i = 0; i < 10; i++) std::cout << arr[i] << " ";

    clsUtil::ShuffleArray(arr, 10);

    std::cout << "\nAfter Shuffle: ";
    for (int i = 0; i < 10; i++) std::cout << arr[i] << " ";

    return 0;
}
```

---

## 🛠️ Requirements: 
- A C++ compiler (GCC, Clang, MSVC, etc.)
