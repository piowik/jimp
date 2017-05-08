//
// Created by Piotrek on 03.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <stdexcept>

using std::stringstream;

namespace moviesubs {
    class InvalidSubtitleLineFormat {

    };

    class NegativeFrameAfterShift {

    };

    class MissingTimeSpecification {

    };

    class OutOfOrderFrames {

    };

    class SubtitleEndBeforeStart: public std::runtime_error {
    public:
        SubtitleEndBeforeStart(const std::string &m, int line): std::runtime_error("At line " + std::to_string(line) + ": " + m) {
            lineAt_ = line;
        }
        int LineAt() const { return lineAt_; };

    private:
        int lineAt_ = 0;
    };

    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) const = 0;
    };


    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) const override;
    };
    
    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) const;
    };
};
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H