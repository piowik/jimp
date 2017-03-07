//
// Created by Piotrek on 07.03.2017.
//

#include "Palindrome.h"
#include <iostream>

bool is_palindrome(std::string str) {
    const char *characters = str.c_str();
    size_t len = str.size();
    char reversed[len];
    for (int i = 0; i < len; i++) {
        reversed[i] = characters[len - 1 - i];
    }
    reversed[len] = '\0';
    return reversed == str;
}