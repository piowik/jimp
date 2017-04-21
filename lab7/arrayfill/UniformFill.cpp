//
// Created by Piotrek on 20.04.2017.
//

#include "UniformFill.h"
namespace arrays {
    UniformFill::UniformFill(int base) {
        value_ = base;
    }

    int UniformFill::Value(int index) const {
        return value_;
    }
}