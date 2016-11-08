/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_TRACK_HPP
#define TURTLE_TRACK_HPP

#include <vector>
#include <utility>

struct Track {
    enum class Color {
        Black = 0,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,
    };

    Color color;
    std::vector<std::pair<int, int> > coords;

    void draw() const;
};

#endif

