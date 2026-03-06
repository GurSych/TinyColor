# TinyColor
My tiny header-only library for terminal coloring

# Using Library

## Library connection

```cpp
#include "TinyColor/TinyColor.hpp"

namespace tcl = gst::tcl; // for convenience
```

> [!NOTE]
> All library functions are in `gst::tcl::` namespace, so that's convenient to use namespace aliases

> [!IMPORTANT]
> This library requires C++20 standard

### CMake fetching

Library is ready to be fetched using CMake's `fetch_content`

```cmake
include(FetchContent)

fetch_content(TinyColor
    GIT_REPOSITORY https://github.com/GurSych/TinyColor
    GIT_TAG        v2.0.0
)
FetchContent_MakeAvailable(TinyColor)

target_link_libraries(foo PRIVATE TinyColor::TinyColor)
```

## Usage documentation

> Library is in development so this section is updated together with library itself

### Terminal coloring & styling

TinyColor provides a simple way to color and style terminal output using functions:<br>

`void set(tcl::OptionList option, std::ostream& stream = std::cout)`<br>
`void set(std::initializer_list<tcl::OptionList> options, std::ostream& stream = std::cout)`<br>
`void reset(std::ostream& stream = std::cout)`

```cpp
tcl::set(tcl::RED);                 // tcl::set(tcl::RED, std::cout);
std::cout << "This text is red" << std::endl;

tcl::set({tcl::RED, tcl::BOLD});    // tcl::set({tcl::RED, tcl::BOLD}, std::cout);
std::cout << "This text is red and bold" << std::endl;

tcl::reset();                       // tcl::reset(std::cout);
std::cout << "This text is back to normal" << std::endl;
```

These functions allow you to set terminal color and style options for any `std::ostream` (`std::cout` by default).<br>

### String colorization

`std::string colorize(const std::string& text, tcl::OptionList... option)`<br>
`std::string colorize(const std::string& text, std::initializer_list<tcl::OptionList> options)`

```cpp
std::cout << tcl::colorize("This text is red", tcl::RED) << std::endl;

std::cout << tcl::colorize("This text is red and bold", tcl::RED, tcl::BOLD) << std::endl;

std::cout << tcl::colorize("This text is red and bold", {tcl::RED, tcl::BOLD}) << std::endl;
```

These functions allow you to colorize a string with terminal color and style options.

### Color codes enumeration

All functions considered above use color codes from `tcl::OptionList` enumeration

    RESET               (0)   Reset all attributes
    BOLD                (1)   Make text bold
    DIM                 (2)   Make text dim
    ITALIC              (3)   Make text italic
    UNDERLINE           (4)   Make text underline
    BLINK               (5)   Make text blink
    REVERSE             (7)   Reverse text and background colors
    CONCEAL             (8)   Conceal text
    STRIKETHROUGH       (9)   Make text strikethrough
      
    DBL_UNDERLINE       (21)  Make text double underline
    NRM_INTENSITY       (22)  Revert to normal intensity
    NO_ITALIC           (23)  Revert italic
    NO_UNDERLINE        (24)  Revert underline
    NO_BLINK            (25)  Revert blink
    NO_REVERSE          (27)  Revert reverse
    NO_CONCEAL          (28)  Revert conceal
    NO_STRIKETHROUGH    (29)  Revert strikethrough
       
    BLACK               (30)  Color text black
    RED                 (31)  Color text red
    GREEN               (32)  Color text green
    YELLOW              (33)  Color text yellow
    BLUE                (34)  Color text blue
    MAGENTA             (35)  Color text magenta
    CYAN                (36)  Color text cyan
    WHITE               (37)  Color text white
    DEFAULT             (39)  Color text default
       
    BKG_BLACK           (40)  Color background black
    BKG_RED             (41)  Color background red
    BKG_GREEN           (42)  Color background green
    BKG_YELLOW          (43)  Color background yellow
    BKG_BLUE            (44)  Color background blue
    BKG_MAGENTA         (45)  Color background magenta
    BKG_CYAN            (46)  Color background cyan
    BKG_WHITE           (47)  Color background white
       
    BRT_BLACK           (90)  Color text bright black
    BRT_RED             (91)  Color text bright red
    BRT_GREEN           (92)  Color text bright green
    BRT_YELLOW          (93)  Color text bright yellow
    BRT_BLUE            (94)  Color text bright blue
    BRT_MAGENTA         (95)  Color text bright magenta
    BRT_CYAN            (96)  Color text bright cyan
    BRT_WHITE           (97)  Color text bright white
      
    BRT_BKG_BLACK       (100) Color background bright black
    BRT_BKG_RED         (101) Color background bright red
    BRT_BKG_GREEN       (102) Color background bright green
    BRT_BKG_YELLOW      (103) Color background bright yellow
    BRT_BKG_BLUE        (104) Color background bright blue
    BRT_BKG_MAGENTA     (105) Color background bright magenta
    BRT_BKG_CYAN        (106) Color background bright cyan
    BRT_BKG_WHITE       (107) Color background bright white

### Moving cursor

`std::string up(int8_t lines = 1)`<br>
`std::string down(int8_t lines = 1)`<br>
`std::string left(int8_t columns = 1)`<br>
`std::string right(int8_t columns = 1)`

```cpp
std::cout << tcl::up();         // moves up 1 line
std::cout << tcl::down(1);      // moves down 1 line
std::cout << tcl::left(5);      // moves left 5 columns
std::cout << tcl::right(-4);    // moves left 4 columns
```

These functions return a string that moves the cursor up, down, left, or right by the specified number of lines or columns (default is 1).

`std::string clear_line()`<br>

This function returns a string that clears the current line.
