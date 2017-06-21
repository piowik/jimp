//
// Created by Piotrek on 04.06.2017.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template<class T, class S>
class SequentialIdGenerator {
public:
    SequentialIdGenerator() {}

    SequentialIdGenerator(const S &id) { id_ = id; }

    T NextValue() {
        id_ = id_ + 1;
        return T(id_ - 1);
    }

private:
    S id_ = 0;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
