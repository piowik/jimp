//
// Created by Piotrek on 20.04.2017.
//

#include "SquaredFill.h"
namespace arrays {
    SquaredFill::SquaredFill(int a) {
        a_ = a;
    }

    SquaredFill::SquaredFill(int a, int b) {
        a_ = a;
        b_ = b;
    }

    int SquaredFill::Value(int index) const {
        return a_*index*index+b_;
    }
}