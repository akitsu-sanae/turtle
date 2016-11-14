/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <unistd.h>

#include "turtle.hpp"
#include "field.hpp"

Field::Field(size_t w, size_t h) :
    m_width(w),
    m_height(h)
{
    m_turtle = std::make_unique<Turtle>(*this);
    m_tracks.emplace_back();
    m_tracks.back().coords.emplace_back(m_turtle->x(), m_turtle->y());
}

Field::~Field() {
    std::printf("\033[2");
}

void Field::update() {
    auto op = m_command_loader.read();
    switch (op->type()) {
    case OpType::Quit:
        m_is_quit = true;
        break;
    case OpType::Go:
    case OpType::Turn:
        m_turtle->update(op, m_tracks.back());
        break;
    case OpType::Load:
        m_command_loader.new_file(op->cast<OpType::Load>().filename);
        break;
    case OpType::Sleep:
        usleep(op->cast<OpType::Sleep>().time);
        break;
    case OpType::Invalid:
        std::printf("\033[31m");
        std::printf("Invalid Command");
        std::printf("\033[39m");
        break;
    }
}

void Field::draw() const {
    std::printf("\033[2 \033[0;0H");
    for (size_t y=0; y<m_height; y++) {
        for (size_t x=0; x<m_width; x++) {
            if (x == 0 || x == m_width-1)
                std::cout << (y%2 ? '|' : 'I');
            else if (y == 0 || y == m_height-1)
                std::cout << (x%2 ? '-' : '=');
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
    for (auto const& track: m_tracks)
        track.draw();
    m_turtle->draw();
    std::printf("\033[%zu;1H(%d, %d)Command: ", m_height, m_turtle->x(), m_turtle->y());
}

