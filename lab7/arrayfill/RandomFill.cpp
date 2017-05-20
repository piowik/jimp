//
// Created by Piotrek on 20.04.2017.
//

#include "RandomFill.h"
#include "../../../../../MinGW/lib/gcc/mingw32/5.3.0/include/c++/bits/unique_ptr.h"

namespace arrays {


    int RandomFill::Value(int index) const {
        return (*distribution_)(*engine_);
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> engine,
                           std::unique_ptr<std::uniform_int_distribution<int>> distribution) {
        engine_ = std::move(engine);
        distribution_ = std::move(distribution);
    }


}