//
// Created by Piotrek on 16.03.2017.
//

#include "MinimalTimeDifference.h"
#include <sstream>
#include <regex>
#include <iostream>

using std::smatch;
using std::regex;
using std::string;
using std::vector;

namespace minimaltimedifference {

    unsigned int ToMinutes(string time_HH_MM) {
        unsigned int ret = (unsigned int) -1;
        regex pattern{R"((\d{1,2}):(\d{2}))"};
        smatch matches;
        if (regex_match(time_HH_MM, matches, pattern)) {
            ret = stoi(matches[1]) * 60 + stoi(matches[2]);
        }
        return ret;
    }

    int FindRightPosition(const vector<int> &numbers, int value) {
        int lowestIndex = 0;
        int i = 1;
        for (int v : numbers)
            if (v <= value) {
                lowestIndex = i;
                i++;
            }
        return lowestIndex;
    }

    int Minimum(int n1, int n2) {
        return n1 < n2 ? n1 : n2;
    }

    unsigned int MinimalTimeDifference(vector<string> times) {
        int minimumTimeDifference = 1440;
        vector<int> timeDifferences;
        for (auto time:times) {
            int timeInMin = ToMinutes(time);
            timeDifferences.insert(timeDifferences.begin() + FindRightPosition(timeDifferences, timeInMin), timeInMin);
        }
        int size = (int) timeDifferences.size();
        for (int i = 0; i < size; i++) {
            int diff1 = abs(timeDifferences[i] - timeDifferences[(i + 1)%size]);
            int diff2 = abs(diff1-1440);
            int diff = Minimum(diff1,diff2);
            if (diff < minimumTimeDifference)
                minimumTimeDifference = diff;
        }
        return minimumTimeDifference;
    }
}