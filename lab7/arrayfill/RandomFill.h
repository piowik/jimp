//
// Created by Piotrek on 20.04.2017.
//

#ifndef JIMP_EXERCISES_RANDOMFILL_H
#define JIMP_EXERCISES_RANDOMFILL_H

#include <memory>
#include <random>
#include "Filler.h"

namespace arrays {


    class RandomFill : public Filler {
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> engine,
                   std::unique_ptr<std::uniform_int_distribution<int>> distribution);

    private:
        int Value(int index) const override;
        std::unique_ptr<std::default_random_engine> engine_;
        std::unique_ptr<std::uniform_int_distribution<int>> distribution_;
    };
}

#endif //JIMP_EXERCISES_RANDOMFILL_H
