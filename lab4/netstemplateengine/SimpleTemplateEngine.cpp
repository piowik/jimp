//
// Created by Piotrek on 27.03.2017.
//

#include "SimpleTemplateEngine.h"

namespace nets {

    View::View(const std::string &str) {
        passedString_ = str;
    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        const char *characters = passedString_.c_str();
        size_t size = passedString_.size();
        int open = 0;
        int close = 0;
        int startPos = -1;
        std::string ret = "";
        for (int i = 0; i < size; i++) {
            if (characters[i] == '{') {
                open++;
                if (open == 2)
                    startPos = i - 1;
            } else if (characters[i] == '}') {
                close++;
                if (open >= 2 && close == 2) {
                    if (open > 2) {
                        for (int j = 2; j < open; j++)
                            ret += "{";
                    }
                    auto toReplace = model.find(passedString_.substr(startPos + open, i - startPos - (open + 1)));
                    if (toReplace != model.end())
                        ret += toReplace->second;
                    open = 0;
                    close = 0;
                }
            } else {
                if (open < 2) {
                    if (open > 0) {
                        for (int j = 0; j < open; j++)
                            ret += "{";
                        open = 0;
                    }
                    if (close > 0) {
                        for (int j = 0; j < close; j++)
                            ret += "}";
                        close = 0;
                    }
                    ret += characters[i];
                } else if (close > 0) { // enough openings but only 1 closing, insert word with brackets
                    ret += passedString_.substr(startPos, i - startPos + 1);
                    open = 0;
                    close = 0;
                }
            }
        }
        if (close > 0) { // there might be some closing bracket left
            for (int i = 0; i < close; i++)
                ret += "}";
        }
        return ret;
    }
}