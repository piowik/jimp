//
// Created by Piotrek on 04.06.2017.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>

namespace profiling {
    template<typename T>
    auto TimeRecorder(T t) {
        static std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
        auto result = (t)();
        std::chrono::duration<double, std::milli> change = std::chrono::high_resolution_clock::now() - startTime;
        return std::pair<decltype(result), double>(result, change.count());
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
