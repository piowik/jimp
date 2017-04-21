//
// Created by Piotrek on 20.04.2017.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <cstdlib>
#include <vector>
#include "Filler.h"
#include "IncrementalFill.h"
#include "RandomFill.h"
#include "UniformFill.h"
#include "SquaredFill.h"

namespace arrays {
    void FillArray(size_t size, const Filler &filler, std::vector<int> *v);
}

#endif //JIMP_EXERCISES_ARRAYFILL_H
