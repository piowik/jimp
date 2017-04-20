//
// Created by Piotrek on 19.04.2017.
//

#include "Word.h"

namespace datastructures {
    Word::Word(const std::string &str = "") {
        word_ = str;
    }

    const std::string &Word::GetWord() const { return word_; }
}