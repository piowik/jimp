//
// Created by Piotrek on 20.04.2017.
//

#ifndef JIMP_EXERCISES_INCREMENTALFILL_H
#define JIMP_EXERCISES_INCREMENTALFILL_H

#include "Filler.h"

namespace arrays {

    class IncrementalFill : public Filler {
    public:
        IncrementalFill() = default;
        IncrementalFill(int base);
        IncrementalFill(int base, int step);

    private:
        int Value(int index) const override;
        int base_ = 0;
        int step_ = 1;
    };
}

#endif //JIMP_EXERCISES_INCREMENTALFILL_H
