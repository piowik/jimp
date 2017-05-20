//
// Created by Piotrek on 20.04.2017.
//

#include "IncrementalFill.h"
namespace arrays {


    int IncrementalFill::Value(int index) const {
        return base_+(index*step_);
    }

    IncrementalFill::IncrementalFill(int base) {
        base_ = base;
    }

    IncrementalFill::IncrementalFill(int base, int step) {
        base_ = base;
        step_ = step;
    }
}