//
// Created by Piotrek on 01.04.2017.
//

#include <iostream>
#include "TextPool.h"


namespace pool {
    TextPool::TextPool() {}

    TextPool::TextPool(const std::initializer_list<std::string> &in) {
        for (auto s : in)
            Intern(s);
    }

    TextPool::~TextPool() {}

    // przenoszenie
    TextPool::TextPool(TextPool &&tPoolMove) {
        std::swap(tPool_, tPoolMove.tPool_);
    }

    // przypisanie przenoszenie
    TextPool &TextPool::operator=(TextPool &&tPoolMove) {
        if (this == &tPoolMove) {
            return tPoolMove;
        }
        tPool_.clear();
        std::swap(tPool_, tPoolMove.tPool_);
        return *this;
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        auto it = tPool_.insert(str);
        /* Zwracana wartość to para zawierająca iterator na wstawiony element oraz zmienna bool która mówi o tym
 * czy wstawienie się powiodło(mógł już istnieć element o tej samej wartości). Jeśli wstawienie nie powiodło się
 * iterator wskazuje na element o wartości elementu wstawianego który już był w zbiorze. */
        return std::experimental::string_view(*(it.first));
    }

    size_t TextPool::StoredStringCount() const {
        return tPool_.size();
    }
}