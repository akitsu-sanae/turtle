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
#include "track.hpp"

struct Turtle {
    int x = 3, y = 2;

    void update(std::unique_ptr<OperationBase> const& op, Track& track) {
        switch (op->type()) {
        case OpType::MoveUp:
            y -= op->cast<OpType::MoveUp>().distance;
            break;
        case OpType::MoveDown:
            y += op->cast<OpType::MoveDown>().distance;
            break;
        case OpType::MoveLeft:
            x -= op->cast<OpType::MoveLeft>().distance;
            break;
        case OpType::MoveRight:
            x += op->cast<OpType::MoveRight>().distance;
            break;
        default:
            abort();
        }
        track.coords.emplace_back(x, y);
    }
    void draw() const {
        std::printf("\033[%d;%dH*", y, x);
    }
};

#endif



