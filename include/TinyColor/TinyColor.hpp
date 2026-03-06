// Tiny header-only library for console coloring
// by Gur-Sych (https://github.com/GurSych)

#ifndef GURSYCH_TINY_COLOR_HPP
#define GURSYCH_TINY_COLOR_HPP

#pragma once

#include <initializer_list>
#include <iostream>
#include <optional>
#include <cstdint>
#include <string>

namespace gst {

    namespace tcl {

        enum class OptionList: int8_t {

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

        constexpr auto RESET            = OptionList::RESET;
        constexpr auto BOLD             = OptionList::BOLD;
        constexpr auto DIM              = OptionList::DIM;
        constexpr auto ITALIC           = OptionList::ITALIC;
        constexpr auto UNDERLINE        = OptionList::UNDERLINE;
        constexpr auto BLINK            = OptionList::BLINK;
        constexpr auto REVERSE          = OptionList::REVERSE;
        constexpr auto CONCEAL          = OptionList::CONCEAL;
        constexpr auto STRIKETHROUGH    = OptionList::STRIKETHROUGH;
        constexpr auto DBL_UNDERLINE    = OptionList::DBL_UNDERLINE;
        constexpr auto NRM_INTENSITY    = OptionList::NRM_INTENSITY;
        constexpr auto NO_ITALIC        = OptionList::NO_ITALIC;
        constexpr auto NO_UNDERLINE     = OptionList::NO_UNDERLINE;
        constexpr auto NO_BLINK         = OptionList::NO_BLINK;
        constexpr auto NO_REVERSE       = OptionList::NO_REVERSE;
        constexpr auto NO_CONCEAL       = OptionList::NO_CONCEAL;
        constexpr auto NO_STRIKETHROUGH = OptionList::NO_STRIKETHROUGH;
        constexpr auto BLACK            = OptionList::BLACK;
        constexpr auto RED              = OptionList::RED;
        constexpr auto GREEN            = OptionList::GREEN;
        constexpr auto YELLOW           = OptionList::YELLOW;
        constexpr auto BLUE             = OptionList::BLUE;
        constexpr auto MAGENTA          = OptionList::MAGENTA;
        constexpr auto CYAN             = OptionList::CYAN;
        constexpr auto WHITE            = OptionList::WHITE;
        constexpr auto DEFAULT          = OptionList::DEFAULT;
        constexpr auto BKG_BLACK        = OptionList::BKG_BLACK;
        constexpr auto BKG_RED          = OptionList::BKG_RED;
        constexpr auto BKG_GREEN        = OptionList::BKG_GREEN;
        constexpr auto BKG_YELLOW       = OptionList::BKG_YELLOW;
        constexpr auto BKG_BLUE         = OptionList::BKG_BLUE;
        constexpr auto BKG_MAGENTA      = OptionList::BKG_MAGENTA;
        constexpr auto BKG_CYAN         = OptionList::BKG_CYAN;
        constexpr auto BKG_WHITE        = OptionList::BKG_WHITE;
        constexpr auto BRT_BLACK        = OptionList::BRT_BLACK;
        constexpr auto BRT_RED          = OptionList::BRT_RED;
        constexpr auto BRT_GREEN        = OptionList::BRT_GREEN;
        constexpr auto BRT_YELLOW       = OptionList::BRT_YELLOW;
        constexpr auto BRT_BLUE         = OptionList::BRT_BLUE;
        constexpr auto BRT_MAGENTA      = OptionList::BRT_MAGENTA;
        constexpr auto BRT_CYAN         = OptionList::BRT_CYAN;
        constexpr auto BRT_WHITE        = OptionList::BRT_WHITE;
        constexpr auto BRT_BKG_BLACK    = OptionList::BRT_BKG_BLACK;
        constexpr auto BRT_BKG_RED      = OptionList::BRT_BKG_RED;
        constexpr auto BRT_BKG_GREEN    = OptionList::BRT_BKG_GREEN;
        constexpr auto BRT_BKG_YELLOW   = OptionList::BRT_BKG_YELLOW;
        constexpr auto BRT_BKG_BLUE     = OptionList::BRT_BKG_BLUE;
        constexpr auto BRT_BKG_MAGENTA  = OptionList::BRT_BKG_MAGENTA;
        constexpr auto BRT_BKG_CYAN     = OptionList::BRT_BKG_CYAN;
        constexpr auto BRT_BKG_WHITE    = OptionList::BRT_BKG_WHITE;

        inline int8_t option_to_ANSI(OptionList option) {
            return static_cast<int8_t>(option);
        }
        inline std::string option_to_ANSI_str(OptionList option) {
            return std::to_string(option_to_ANSI(option));
        }

        template<typename... Ts>
        concept AllOptionLists = (std::same_as<Ts, OptionList> && ...);

        inline void set(OptionList option, std::ostream& stream = std::cout);
        inline void set(std::initializer_list<OptionList> options, std::ostream& stream = std::cout);
        inline void reset(std::ostream& stream = std::cout);

        template<AllOptionLists... OTs>
        inline std::string colorize(const std::string& text, OTs... options);
        inline std::string colorize(const std::string& text, std::initializer_list<OptionList> options);

        inline std::string clear_line();
        inline std::string up(int8_t lines = 1);
        inline std::string down(int8_t lines = 1);
        inline std::string left(int8_t columns = 1);
        inline std::string right(int8_t columns = 1);

    }

}

inline void gst::tcl::set(gst::tcl::OptionList option, std::ostream& stream) {
    stream << "\033[" << option_to_ANSI_str(option) << "m";
}

inline void gst::tcl::set(std::initializer_list<gst::tcl::OptionList> options, std::ostream& stream) {
    if (options.size() == 0) {
        return;
    }
    std::string out{"\033["};
    for (auto option : options) {
        out += option_to_ANSI_str(option) + ';';
    }
    out.pop_back();
    out += "m";
    stream << out;
}

inline void gst::tcl::reset(std::ostream& stream) {
    stream << "\033[0m";
}

template<gst::tcl::AllOptionLists... OTs>
inline std::string gst::tcl::colorize(const std::string& text, OTs... options) {
    if constexpr (sizeof...(options) == 0) {
        return text;
    }
    std::string out{"\033["};
    ((out += option_to_ANSI_str(options) + ';'), ...);
    out.pop_back();
    out += "m" + text + "\033[0m";
    return out;
}

inline std::string gst::tcl::colorize(const std::string& text, std::initializer_list<gst::tcl::OptionList> options) {
    std::string out = "\033[";
    for (auto option : options) {
        out += option_to_ANSI_str(option) + ';';
    }
    out.pop_back();
    out += "m" + text + "\033[0m";
    return out;
}

inline std::string gst::tcl::clear_line() {
    return "\033[2K";
}

inline std::string gst::tcl::up(int8_t lines) {
    if (lines < 0) {
        return gst::tcl::down(-lines);
    }
    std::string out{"\033["};
    out += std::to_string(lines) + "A";
    return out;
}

inline std::string gst::tcl::down(int8_t lines) {
    if (lines < 0) {
        return gst::tcl::up(-lines);
    }
    std::string out{"\033["};
    out += std::to_string(lines) + "B";
    return out;
}

inline std::string gst::tcl::left(int8_t columns) {
    if (columns < 0) {
        return gst::tcl::right(-columns);
    }
    std::string out{"\033["};
    out += std::to_string(columns) + "D";
    return out;
}

inline std::string gst::tcl::right(int8_t columns) {
    if (columns < 0) {
        return gst::tcl::left(-columns);
    }
    std::string out{"\033["};
    out += std::to_string(columns) + "C";
    return out;
}

#endif // GURSYCH_TINY_COLOR_HPP
