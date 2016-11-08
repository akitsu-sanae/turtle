/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include "utility.hpp"
#include "turtle.hpp"
#include "track.hpp"
#include "operation.hpp"

void Turtle::update(std::unique_ptr<OperationBase> const& op, Track& track) {
    switch (op->type()) {
    case OpType::TurnLeft:
        dir = static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
        break;
    case OpType::TurnRight:
        dir = static_cast<Direction>((static_cast<int>(dir) - 1 + 4) % 4);
        break;
    case OpType::Forward:
        switch (dir) {
        case Direction::Up:
            y -= op->cast<OpType::Forward>().distance;
            break;
        case Direction::Down:
            y += op->cast<OpType::Forward>().distance;
            break;
        case Direction::Right:
            x += op->cast<OpType::Forward>().distance;
            break;
        case Direction::Left:
            x -= op->cast<OpType::Forward>().distance;
            break;
        }
        break;
    case OpType::Backward:
        switch (dir) {
        case Direction::Up:
            y += op->cast<OpType::Backward>().distance;
            break;
        case Direction::Down:
            y -= op->cast<OpType::Backward>().distance;
            break;
        case Direction::Right:
            x -= op->cast<OpType::Backward>().distance;
            break;
        case Direction::Left:
            x += op->cast<OpType::Backward>().distance;
            break;
        }
        break;
    default:
        abort();
    }
    track.coords.emplace_back(x, y);
}

void Turtle::draw() const {
    std::printf("\033[%d;%dH*", y, x);
    switch (dir) {
    case Direction::Up:
        std::printf("\033[%d;%dH^", y-1, x);
        break;
    case Direction::Left:
        std::printf("\033[%d;%dH<", y, x-1);
        break;
    case Direction::Down:
        std::printf("\033[%d;%dHV", y+1, x);
        break;
    case Direction::Right:
        std::printf("\033[%d;%dH>", y, x+1);
        break;
    }
}


