//
// Created by Piotrek on 19.04.2017.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>

namespace datastructures {
    class Word {
    public:
        Word() = default;

        Word(const std::string &str);

        const std::string &GetWord() const;

    private:
        std::string word_;
    };

    // map req
    inline bool operator==(const Word &s1, const Word &s2) {
        return s1.GetWord() == s2.GetWord();
    }

    inline bool operator<(const Word &s1, const Word &s2) {
        return s1.GetWord() < s2.GetWord();
    }
}

#endif //JIMP_EXERCISES_WORD_H
