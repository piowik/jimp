//
// Created by Piotrek on 27.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>

namespace nets {
    class JsonValue {
    public:
        JsonValue(int val);

        JsonValue(double val);

        JsonValue(bool val);

        JsonValue(std::string str);

        JsonValue(std::vector<JsonValue> vec);

        JsonValue(std::map<std::string, JsonValue> map);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        int intVal_ = _NULL;
        double doubleVal_ = _NULL;
        bool boolVal_ = _NULL;
        std::string stringVal_ = "";
        std::vector<JsonValue> vectorVal_;
        std::map<std::string,JsonValue> map_;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
