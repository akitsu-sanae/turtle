/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_FIELD_HPP
#define TIRTLE_FIELD_HPP

#include <vector>
#include <memory>

#include "operation.hpp"
#include "command_loader.hpp"
#include "track.hpp"

struct Turtle;

struct Field {
    explicit Field(size_t, size_t);
    ~Field();

    void update();
    void draw() const;

    bool is_quit() const { return m_is_quit; }
    size_t width() const { return m_width; }
    size_t height() const { return m_height; }
private:
    size_t const m_width;
    size_t const m_height;
    bool m_is_quit = false;
    bool m_is_pen_down = true;
    std::unique_ptr<Turtle> m_turtle;
    CommandLoader m_command_loader;
    std::vector<Track> m_tracks;
};

#endif
