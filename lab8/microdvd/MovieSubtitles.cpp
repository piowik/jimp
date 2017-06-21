//
// Created by Piotrek on 03.05.2017.
//

#include <iostream>
#include <regex>
#include "MovieSubtitles.h"

namespace moviesubs {
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) const {
        if (fps <= 0)
            throw std::invalid_argument("Invalid fps");
        int offset = (int)(fps*delay*0.001);
        std::regex wzorzec{R"(\{(\d+)\}\{(\d+)\}(.*))"};
        std::smatch matches;
        std::string curStr = "";
        int line = 1;
        while(getline(*in,curStr)) {
            if (std::regex_match(curStr, matches, wzorzec)) {
                int t1 = std::stoi(matches[1])+offset;
                int t2 = std::stoi(matches[2])+offset;
                if (t1 > t2)
                    throw SubtitleEndBeforeStart(curStr, line);
                if (t1 < 0 || t2 < 0)
                    throw NegativeFrameAfterShift();
                *out << "{" << t1 << "}";
                *out << "{" << t2 << "}";
                *out << matches[3];
                *out << "\n";
                line++;
            }
            else
                throw InvalidSubtitleLineFormat();
        }
    }

    long ToMs(int times[4]) {
        long ret = times[0]*3600*1000;
        ret += times[1]*60*1000;
        ret += times[2]*1000;
        ret += times[3];
        return ret;
    }

    std::string MsToSubRipString(long ms) {
        std::stringstream out;
        long time = (ms/3600)/1000;
        if (time < 10)
            out << "0";
        out << time << ":";
        ms%=3600*1000;
        time = (ms/60)/1000;
        if (time < 10)
            out << "0";
        out << time << ":";
        ms%=60*1000;
        time = ms/1000;
        if(time < 10)
            out << "0";
        out << time << ",";
        ms%=1000;
        if (ms < 100)
            out << "0";
        if (ms < 10)
            out << "0";
        out << ms;
        return out.str();
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) const {
        if (fps <= 0)
            throw std::invalid_argument("Invalid fps");
        int line = 1;
        std::string curStr = "";
        std::regex wzorzec{R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
        std::smatch matches;
        while (getline(*in, curStr)) {
            if (line != std::stoi(curStr))
                throw OutOfOrderFrames();
            *out << curStr;
            *out << "\n";
            getline(*in, curStr); // 2 linijka - czasy
            if (std::regex_match(curStr, matches, wzorzec)) {
                int t1[4] = {std::stoi(matches[1]), std::stoi(matches[2]), std::stoi(matches[3]),
                             std::stoi(matches[4])};
                int t2[4] = {std::stoi(matches[5]), std::stoi(matches[6]), std::stoi(matches[7]),
                             std::stoi(matches[8])};
                long ms1 = ToMs(t1);
                long ms2 = ToMs(t2);
                if (ms1 > ms2)
                    throw SubtitleEndBeforeStart(curStr, line);
                ms1 += delay;
                ms2 += delay;
                if (ms1 < 0 || ms2 < 0)
                    throw NegativeFrameAfterShift();
                *out << MsToSubRipString(ms1) << " --> " << MsToSubRipString(ms2) << "\n";
            } else
                throw InvalidSubtitleLineFormat();
            while (curStr != "") {
                getline(*in, curStr);
                *out << curStr;
                if (!in->eof())
                    *out << "\n";
            }
            line++;
        }
    }
}