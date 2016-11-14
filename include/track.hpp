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

    explicit Track(int x, int y) {
        m_coords.emplace_back(x, y);
    }

    void put(int x, int y) {
        m_coords.emplace_back(x, y);
    }

    void draw() const;
private:
    Color m_color = Color::Red;
    std::vector<std::pair<int, int> > m_coords;
};

#endif

