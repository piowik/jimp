//
// Created by Piotrek on 07.03.2017.
//

#include <iostream>
#include "Palindrome.h"
using namespace std;

int main() {
    string text;
    int option;
    bool exit = false;
    while (!exit) {
        cout << "Co chcesz zrobic?: " << endl;
        cout << "1. Sprawdz palindrom" << endl;
        cout << "2. Wyjscie" << endl;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Wprowadz tekst: ";
                cin >> text;
                if (is_palindrome(text))
                    cout << "jest palindromem" << endl;
                else
                    cout << "nie jest palindromem" << endl;
                break;

            case 2:
                exit = true;
                break;

            default:
                cout << "Nieznana opcja. Sprobuj jeszcze raz." << endl;
        }
    }
    return 0;
}