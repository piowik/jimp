//
// Created by Piotrek on 19.04.2017.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures {
    class Counts {
    public:
        Counts();
        Counts(int count);
        int GetCount() const;

        Counts &operator++() {
            count_ += 1;
            return *this;
        };

        bool operator<(const Counts &s2) const {
            return count_ < s2.count_;
        }

        bool operator>(const Counts &s2) const {
            return count_ > s2.count_;
        }

        bool operator==(const Counts &s2) const {
            return count_ == s2.count_;
        }

    private:
        int count_;
    };
}

#endif //JIMP_EXERCISES_COUNTS_H
