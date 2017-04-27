//
// Created by Piotrek on 27.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

namespace nets {
    class View {
    public:
        View(const std::string &str);

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
        std::string passedString_;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
