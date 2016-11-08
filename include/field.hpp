/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_FIELD_HPP
#define TIRTLE_FIELD_HPP

#include <vector>
#include <algorithm>

#include "turtle.hpp"
#include "operation.hpp"
#include "command_loader.hpp"
#include "track.hpp"

template<size_t W, size_t H>
struct Field {
    static constexpr size_t Width = W;
    static constexpr size_t Height = H;
    Turtle turtle;

    explicit Field() {
        m_tracks.emplace_back();
        m_tracks.back().coords.emplace_back(turtle.x, turtle.y);
    }
    ~Field() {
        std::printf("\033[2");
    }
    void update() {
        auto op = m_command_loader.read();
        switch (op->type()) {
        case OpType::Quit:
            m_is_quit = true;
            break;
        case OpType::Forward:
        case OpType::Backward:
        case OpType::TurnLeft:
        case OpType::TurnRight:
            turtle.update(op, m_tracks.back());
            break;
        case OpType::Load:
            m_command_loader.new_file(op->cast<OpType::Load>().filename);
            break;
        case OpType::Invalid:
            std::printf("\033[31m");
            std::printf("Invalid Command");
            std::printf("\033[39m");
            break;
        }
    }

    void draw() const {
        std::printf("\033[2 \033[0;0H");
        for (size_t y=0; y<Height; y++) {
            for (size_t x=0; x<Width; x++) {
                if (x == 0 || x == Width-1)
                    std::cout << (y%2 ? '|' : 'I');
                else if (y == 0 || y == Height-1)
                    std::cout << (x%2 ? '-' : '=');
                else
                    std::cout << ' ';
            }
            std::cout << std::endl;
        }
        for (auto const& track: m_tracks)
            track.draw();
        turtle.draw();
        std::printf("\033[%zu;1H(%d, %d)Command: ", Height, turtle.x, turtle.y);
    }
    bool is_quit() const { return m_is_quit; }
private:
    bool m_is_quit = false;
    CommandLoader m_command_loader;
    std::vector<Track> m_tracks;
};

#endif
