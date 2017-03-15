//
// Created by Piotrek on 13.03.2017.
//

#include <cmath>
#include <vector>
#include <cstdlib>
#include "GreatestProduct.h"

using std::vector;

int GreatestProduct(const vector<int> &numbers, int k) {
    vector<int> vectorPositive;
    vector<int> vectorNegative;
    for (int n : numbers) {
        bool isNegative = false;
        if (n < 0)
            isNegative = true;
        if (isNegative && (vectorNegative.size() == 0))
            vectorNegative.emplace_back(n);
        else if (!isNegative && (vectorPositive.size() == 0))
            vectorPositive.emplace_back(n);
        else {
            int index = 0;
            if (isNegative) {
                index = FindSortedPosition(vectorNegative, n);
                if (index >= 0)
                    vectorNegative.insert(vectorNegative.begin() + index, n);
            } else {
                index = FindSortedPosition(vectorPositive, n);
                if (index >= 0)
                    vectorPositive.insert(vectorPositive.begin() + index, n);
                if (vectorPositive.size() > k) // nie ma sensu trzymac, w przeciwienstwie do ujemnych
                    vectorPositive.erase(vectorPositive.begin());
            }
        }
    }
    int ret = 1;
    int positiveOffset = 0;
    int negativeOffset = 0;
    int negativeStart = 0;
    int done = 0;
    while (done < k) {
        if ((k - done) == 1 || (vectorNegative.size() - negativeOffset < 2)) {
            if (vectorPositive.size() - positiveOffset > 0) {
                ret *= vectorPositive[vectorPositive.size() - 1 - positiveOffset];
                done++;
                positiveOffset++;
            } else {
                ret *= vectorNegative[negativeStart];
                negativeStart++;
                done++;
            }
        } else if (vectorPositive.size() == 0 && (k % 2) != 0) {
            ret *= vectorNegative[negativeStart];
            negativeStart++;
            done++;
        } else {
            int positiveMult = 0;
            if (vectorPositive.size() - positiveOffset >= 2)
                positiveMult = vectorPositive[vectorPositive.size() - positiveOffset - 1] *
                               vectorPositive[vectorPositive.size() - positiveOffset - 2];
            int negativeMult = vectorNegative[vectorNegative.size() - negativeOffset - 1] *
                               vectorNegative[vectorNegative.size() - negativeOffset - 2];
            if (positiveMult >= negativeMult) {
                positiveOffset += 2;
                ret *= positiveMult;
            } else {
                negativeOffset += 2;
                ret *= negativeMult;
            }
            done += 2;
        }
    }
    return ret;
}

int FindSortedPosition(const vector<int> &numbers, int testValue) {
    int lowestIndex = 0;
    if (testValue < 0)
        testValue = labs(testValue);
    int i = 1;
    for (int v : numbers) {
        v = labs(v);
        if (v <= testValue) {
            lowestIndex = i;
            i++;
        }
    }
    return lowestIndex;
}