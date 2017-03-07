//
// Created by Piotrek on 07.03.2017.
//

#include <iostream>
#include "Palindrome.h"
using namespace std;

int main() {
    string tekst;
    cout<<"Wprowadz tekst: ";
    cin>>tekst;
    if (is_palindrome(tekst))
        cout << " jest palindromem" << endl;
    else
        cout << " nie jest palindromem";
    return 0;
}