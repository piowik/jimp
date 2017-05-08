//
// Created by Piotrek on 19.04.2017.
//

#include "Counts.h"

namespace datastructures {
    Counts::Counts() {
        count_ = 0;
    }
    Counts::Counts(int count) {
        count_ = count;
    }

    int Counts::GetCount() const {
        return count_;
    }
}