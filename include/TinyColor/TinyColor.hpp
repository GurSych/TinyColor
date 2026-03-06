// Tiny header-only library for console coloring
// by Gur-Sych (https://github.com/GurSych)

#ifndef GURSYCH_TINY_COLOR_HPP
#define GURSYCH_TINY_COLOR_HPP

#pragma once

#include <initializer_list>
#include <iostream>
#include <cstdint>
#include <string>

namespace tcl {

    enum OptionList {

        RESET         = 0,
        BOLD          = 1,
        DIM           = 2,
        ITALIC        = 3,
        UNDERLINE     = 4,
        BLINK         = 5,
        REVERSE       = 7,
        CONCEAL       = 8,
        STRIKETHROUGH = 9,

        DBL_UNDERLINE    = 21,
        NRM_INTENSITY    = 22,
        NO_ITALIC        = 23,
        NO_UNDERLINE     = 24,
        NO_BLINK         = 25,
        NO_REVERSE       = 27,
        NO_CONCEAL       = 28,
        NO_STRIKETHROUGH = 29,

        BLACK       = 30,
        RED         = 31,
        GREEN       = 32,
        YELLOW      = 33,
        BLUE        = 34,
        MAGENTA     = 35,
        CYAN        = 36,
        WHITE       = 37,
        DEFAULT     = 39,

        BKG_BLACK   = 40,
        BKG_RED     = 41,
        BKG_GREEN   = 42,
        BKG_YELLOW  = 43,
        BKG_BLUE    = 44,
        BKG_MAGENTA = 45,
        BKG_CYAN    = 46,
        BKG_WHITE   = 47,

        BRT_BLACK   = 90,
        BRT_RED     = 91,
        BRT_GREEN   = 92,
        BRT_YELLOW  = 93,
        BRT_BLUE    = 94,
        BRT_MAGENTA = 95,
        BRT_CYAN    = 96,
        BRT_WHITE   = 97,

        BRT_BKG_BLACK   = 100,
        BRT_BKG_RED     = 101,
        BRT_BKG_GREEN   = 102,
        BRT_BKG_YELLOW  = 103,
        BRT_BKG_BLUE    = 104,
        BRT_BKG_MAGENTA = 105,
        BRT_BKG_CYAN    = 106,
        BRT_BKG_WHITE   = 107,

    };

    inline void set(OptionList option, std::ostream& stream = std::cout);
    inline void set(std::initializer_list<OptionList> options, std::ostream& stream = std::cout);
    inline void reset(std::ostream& stream = std::cout);

    inline std::string colorize(const std::string& text, OptionList option);
    inline std::string colorize(const std::string& text, std::initializer_list<OptionList> options);

    inline std::string clear_line();
    inline std::string up(int16_t lines);
    inline std::string down(int16_t lines);
    inline std::string left(int16_t columns);
    inline std::string right(int16_t columns);

}

inline void tcl::set(OptionList option, std::ostream& stream) {
    stream << "\033[" << option << "m";
}

inline void tcl::set(std::initializer_list<OptionList> options, std::ostream& stream) {
    std::string out = "\033[";
    for (auto option : options) {
        out += std::to_string(option) + ";";
    }
    out.pop_back();
    out += "m";
    stream << out;
}

inline void tcl::reset(std::ostream& stream) {
    stream << "\033[" << RESET << "m";
}

inline std::string tcl::colorize(const std::string& text, OptionList option) {
    std::string out = "\033[";
    out += std::to_string(option) + "m" + text + "\033[" + std::to_string(RESET) + "m";
    return out;
}

inline std::string tcl::colorize(const std::string& text, std::initializer_list<OptionList> options) {
    std::string out = "\033[";
    for (auto option : options) {
        out += std::to_string(option) + ";";
    }
    out.pop_back();
    out += "m" + text + "\033[" + std::to_string(RESET) + "m";
    return out;
}

inline std::string tcl::clear_line() {
    return "\033[2K";
}

inline std::string tcl::up(int16_t lines) {
    if (lines < 0) {
        return tcl::down(-lines);
    }
    std::string out = "\033[";
    out += std::to_string(lines) + "A";
    return out;
}

inline std::string tcl::down(int16_t lines) {
    if (lines < 0) {
        return tcl::up(-lines);
    }
    std::string out = "\033[";
    out += std::to_string(lines) + "B";
    return out;
}

inline std::string tcl::left(int16_t columns) {
    if (columns < 0) {
        return tcl::right(-columns);
    }
    std::string out = "\033[";
    out += std::to_string(columns) + "D";
    return out;
}

inline std::string tcl::right(int16_t columns) {
    if (columns < 0) {
        return tcl::left(-columns);
    }
    std::string out = "\033[";
    out += std::to_string(columns) + "C";
    return out;
}

#endif // GURSYCH_TINY_COLOR_HPP
