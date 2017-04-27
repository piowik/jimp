//
// Created by Piotrek on 01.04.2017.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool {
    class TextPool {
    public:
        TextPool();

        TextPool(const std::initializer_list<std::string> &elements);

        std::experimental::string_view Intern(const std::string &str);

        TextPool(TextPool &&tp);

        TextPool &operator=(TextPool &&tp);

        TextPool(const TextPool &) = delete;

        TextPool &operator=(const TextPool &) = delete;

        ~TextPool();

        size_t StoredStringCount() const;

    private:
        std::set<std::string> tPool_;
    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H
