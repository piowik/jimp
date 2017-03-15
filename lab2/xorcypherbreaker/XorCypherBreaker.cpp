//
// Created by Piotrek on 12.03.2017.
//

#include "XorCypherBreaker.h"
#include <algorithm>

using std::find;
using std::vector;
using std::string;

string Decrypt(const vector<char> &cryptogram, string key) {
    int i = 0;
    string decryptedStr;
    for (char c : cryptogram) {
        decryptedStr += c ^ (int) key[i];
        i++;
        i = i % 3;
    }
    return decryptedStr;
}

int DictionaryTest(string decrypted, const vector<string> &dictionary) {
    int matches = 0;
    for (string s:dictionary)
        if (decrypted.find(s) != std::string::npos)
            matches++;
    return matches;
}


string XorCypherBreaker(const vector<char> &cryptogram,
                        int key_length,
                        const vector<string> &dictionary) {
    int bestCase = 0;
    string bestKey = "";
    string key = "aaa";
    while (key != "zzz") {
        string decrypted = Decrypt(cryptogram, key);
        int found = DictionaryTest(decrypted, dictionary);
        if (found > bestCase) {
            bestCase = found;
            bestKey = key;
        }
        int i = key_length - 1;
        bool changed = false;
        while (!changed) {
            if (key[i] != 'z') {
                key[i]++;
                changed = true;
            } else if (i != 0) {
                key[i] = 'a';
                i--;
            }
        }
    }
    return bestKey;
}