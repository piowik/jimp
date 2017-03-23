//
// Created by Piotrek on 13.03.2017.
//

#include <algorithm>
#include "Polybius.h"

/*      1   2   3   4   5
 * 1    a   b   c   d   e
 * 2    f   g   h   ij  k
 * 3    l   m   n   o   p
 * 4    p   r   s   t   u
 * 5    v   w   x   y   z
 * */

char **PolybiusTable() {
    char c = 'a';
    char **tab = new char *[5];
    for (int i = 0; i < 5; i++) {
        tab[i] = new char[5];
        for (int j = 0; j < 5; j++) {
            if (c == 'j')
                c++; // pomija j
            tab[i][j] = c;
            c++;
        }
    }
    return tab;
}

std::string PolybiusCrypt(std::string message) {
    std::string encrypted;
    char **tab = PolybiusTable();
    std::transform(message.begin(), message.end(), message.begin(), ::tolower);
    const char *msg = message.c_str();
    size_t len = message.size();
    for (int k = 0; k < len; k++) {
        char c = msg[k];
        if (c == 'j')
            c = 'i';
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (tab[i][j] == c)
                    encrypted += std::to_string((i + 1) * 10 + j + 1);
    }
    for (int i = 0; i < 5; i++)
        delete[] tab[i];
    delete[] tab;
    return encrypted;
}

std::string PolybiusDecrypt(std::string crypted) {
    std::string decrypted;
    char **tab = PolybiusTable();
    const char *msg = crypted.c_str();
    size_t len = crypted.size();
    for (int k = 0; k < len; k += 2)
        decrypted += tab[msg[k] - 48 - 1][msg[k + 1] - 48 - 1];
    for (int i = 0; i < 5; i++)
        delete[] tab[i];
    delete[] tab;
    return decrypted;
}