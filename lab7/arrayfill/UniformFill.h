//
// Created by Piotrek on 20.04.2017.
//

#ifndef JIMP_EXERCISES_UNIFORMFILL_H
#define JIMP_EXERCISES_UNIFORMFILL_H

#include "Filler.h"

namespace arrays {


    class UniformFill : public Filler {
    public:
        UniformFill() = default;
        UniformFill(int base);

    private:
        int Value(int index) const override;
        int value_ = 0;
    };
}

#endif //JIMP_EXERCISES_UNIFORMFILL_H
