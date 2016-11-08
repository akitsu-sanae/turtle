/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <cstdio>
#include "utility.hpp"

#include "track.hpp"

void Track::draw() const {
    std::printf("\033[%dm", 30 + static_cast<int>(Color::Red));
    auto current_x = coords[0].first;
    auto current_y = coords[0].second;

    for (auto const& target: coords) {
        while (true) {
            auto diff_x = clamp(target.first - current_x, 1);
            auto diff_y = clamp(target.second - current_y, 1);
            current_x += diff_x;
            current_y += diff_y;
            std::printf("\033[%d;%dH+", current_y, current_x);
            if (diff_x == 0 && diff_y == 0)
                break;
        }
    }
    std::printf("\033[%dm", 30 + static_cast<int>(Color::White));
}

