//
// Created by Piotrek on 13.03.2017.
//
#include <iostream>
#include <fstream>
#include <Polybius.h>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        cout << "Za malo argumentow" << endl;
        return 0;
    }
    int option = atoi(argv[3]);
    if (option != 0 && option != 1) {
        cout << "Nieznana opcja" << endl;
        return 0;
    }
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Blad z plikiem wejsciowym" << endl;
        return 0;
    }
    ofstream outputFile(argv[2], std::ios_base::in | std::ios_base::app);
    if (!outputFile) {
        cout << "Blad z plikiem wyjsciowym" << endl;
        return 0;
    }
    char word[64];
    while (inputFile >> word) {
        cout << word;
        if (option == 0)
            outputFile << PolybiusDecrypt(word) << " ";
        else
            outputFile << PolybiusCrypt(word) << " ";
    }
    outputFile.close();
    inputFile.close();
    return 0;
}