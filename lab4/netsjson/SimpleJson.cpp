//
// Created by Piotrek on 27.03.2017.
//

#include <sstream>
#include <map>
#include "SimpleJson.h"

namespace nets {
    std::string PrepareString(std::string str) {
        std::string output = "\"";
        const char *characters = str.c_str();
        size_t size = str.length();
        for (int i = 0; i < size; i++) {
            if (characters[i] == '\\' || characters[i] == '\"') {
                output += '\\';
            }
            output += characters[i];
        }
        output += "\"";
        return output;
    }

    JsonValue::JsonValue(int val) {
        intVal_ = val;
    }

    JsonValue::JsonValue(double val) {
        doubleVal_ = val;
    }

    JsonValue::JsonValue(bool val) {
        boolVal_ = val;
    }

    JsonValue::JsonValue(std::string str) {
        stringVal_ = PrepareString(str);
    }

    JsonValue::JsonValue(std::vector<JsonValue> vec) {
        vectorVal_ = vec;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> map) {
        std::map<std::string, JsonValue> returnMap;
        for (auto const &e: map) {
            returnMap.emplace(PrepareString(e.first), e.second);
        }
        map_ = returnMap;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        auto it = map_.find(PrepareString(name));
        if (it != map_.end())
            return it->second;
    }

    std::string JsonValue::ToString() const {
        std::stringstream ret2;
        if (intVal_ != _NULL)
            ret2 << intVal_;
        else if (doubleVal_ != _NULL)
            ret2 << doubleVal_;
        else if (!stringVal_.empty())
            ret2 << stringVal_;
        else if (vectorVal_.size() > 0) {
            ret2 << "[";
            for (int i = 0; i < vectorVal_.size(); i++) {
                ret2 << vectorVal_[i].ToString();
                if (i != vectorVal_.size() - 1) {
                    ret2 << ", ";
                }
            }
            ret2 << "]";

        } else if (map_.size() > 0) {
            ret2 << "{";
            int i = 0;
            size_t mapSize = map_.size();
            for (auto const &e: map_) {
                ret2 << e.first << ": " << e.second.ToString();
                i++;
                if (i < mapSize)
                    ret2 << ", ";
            }
            ret2 << "}";
        } else {
            if (boolVal_)
                ret2 << "true";
            else
                ret2 << "false";
        }
        return ret2.str();
    }

}