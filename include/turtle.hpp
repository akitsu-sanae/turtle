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
    void update(std::unique_ptr<OperationBase> const&, Track&);
    void draw() const;

    int x() const { return m_x; }
    int y() const { return m_y; }
private:
    int m_x = 3, m_y = 2;
    Direction m_dir = Direction::Down;
};

#endif



