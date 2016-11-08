/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_HPP
#define TIRTLE_HPP

#include <memory>

struct Track;
struct OperationBase;

struct Turtle {
    enum class Direction {
        Up,
        Left,
        Down,
        Right
    };

    int x = 3, y = 2;
    Direction dir = Direction::Down;

    void update(std::unique_ptr<OperationBase> const&, Track&);

    void draw() const;
};

#endif



