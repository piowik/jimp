//
// Created by Piotrek on 16.03.2017.
//

#include "TinyUrl.h"

using std::unique_ptr;
using std::make_unique;

using std::string;

namespace tinyurl {

    std::array<char, 6> startingHash = {'0', '0', '0', '0', '0', '0'};

    unique_ptr<TinyUrlCodec> Init() {
        unique_ptr<TinyUrlCodec> uniqueTinyUrlPtr = make_unique<TinyUrlCodec>();
        return uniqueTinyUrlPtr;
    }

    void SetEntryData(string url, string encoded, std::unique_ptr<TinyUrlCodec> *tinyUrlCodec) {
        (*tinyUrlCodec)->tinyUrlEntry[encoded] = url;
    }

    void NextHash(std::array<char, 6> *state) {
        for (int i = 5; i >= 0; i--) {
            char el = (*state)[i];
            if (el != 'z') {
                int offset = 1;
                if (el == '9')
                    offset = 8;
                else if (el == 'Z')
                    offset = 7;
                (*state)[i] += offset;
                break;
            } else
                (*state)[i] = '0';
        }
    }

    string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        for (auto it = (*codec)->tinyUrlEntry.begin();
             it != (*codec)->tinyUrlEntry.end(); ++it) // checks if url already encoded, return hash
            if (it->second == url)
                return it->first;
        string encodedUrl;
        for (char c : startingHash)
            encodedUrl += c;
        SetEntryData(url, encodedUrl, codec);
        NextHash(&startingHash);
        return encodedUrl;
    }

    string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        if (codec->tinyUrlEntry.find(hash) != codec->tinyUrlEntry.end())
            return codec->tinyUrlEntry[hash];
        else
            return "notfound";
    }

}