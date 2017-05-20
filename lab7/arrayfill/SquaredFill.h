//
// Created by Piotrek on 20.04.2017.
//

#ifndef JIMP_EXERCISES_SQUAREDFILL_H
#define JIMP_EXERCISES_SQUAREDFILL_H

#include "Filler.h"

namespace arrays {

    class SquaredFill : public Filler {
    public:
        SquaredFill() = default;
        SquaredFill(int a);
        SquaredFill(int a, int b);

    private:
        int Value(int index) const override;
        int a_ = 1;
        int b_ = 0;
    };
}

#endif //JIMP_EXERCISES_SQUAREDFILL_H
