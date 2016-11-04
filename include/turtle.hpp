/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_HPP
#define TIRTLE_HPP

#include <cstdio>

#include "operation.hpp"

struct Turtle {
    int x = 3, y = 2;

    void update(Operation::Type type) {
        switch (type) {
        case Operation::Type::MoveUp:
            y--;
            break;
        case Operation::Type::MoveDown:
            y++;
            break;
        case Operation::Type::MoveLeft:
            x--;
            break;
        case Operation::Type::MoveRight:
            x++;
            break;
        default:
            abort();
        }
    }
    void draw() const {
        std::printf("\033[%d;%dH*", y, x);
    }
};

#endif



