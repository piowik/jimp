//
// Created by Piotrek on 07.03.2017.
//

#include <iostream>
#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max) {
    if (max < 0)
        return 0;
    uint64_t ret = 0;
    for (int i = 0; i < max; i++) {
        std::string iStr = std::to_string(i);
        if (is_palindrome(iStr) && is_palindrome(DecimalToBinaryString(i)))
            ret += i;
    }
    return ret;
}

std::string DecimalToBinaryString(int number) {
    int i = 0;
    int bin[50];
    while (number) {
        bin[i] = number % 2;
        i++;
        number /= 2;
    }
    bin[i] = '\0';
    char ret[i];
    for (int j = 0; j < i; j++)
        ret[j] = (char) (bin[i - j - 1] + 48);
    ret[i] = '\0';
    return ret;
}

bool is_palindrome(std::string str) {
    const char *characters = str.c_str();
    size_t len = str.size();
    char reversed[len];
    for (int i = 0; i < len; i++)
        reversed[i] = characters[len - 1 - i];
    reversed[len] = '\0';
    return reversed == str;
}