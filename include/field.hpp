/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_FIELD_HPP
#define TIRTLE_FIELD_HPP

#include <array>
#include <algorithm>

#include "turtle.hpp"
#include "operation.hpp"
#include "command_loader.hpp"

template<size_t W, size_t H>
struct Field {
    static constexpr size_t Width = W;
    static constexpr size_t Height = H;
    Turtle turtle;

    explicit Field() {
        std::fill(std::begin(m_maptip), std::end(m_maptip), '_');
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
        case OpType::MoveUp:
        case OpType::MoveDown:
        case OpType::MoveLeft:
        case OpType::MoveRight:
            turtle.update(op);
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
        turtle.draw();
        std::printf("\033[%zu;1H(%d, %d)Command: ", Height, turtle.x, turtle.y);
    }
    char at(size_t x, size_t y) const {
        return m_maptip.at(x + y*Width);
    }
    bool is_quit() const { return m_is_quit; }
private:
    bool m_is_quit = false;
    CommandLoader m_command_loader;
    std::array<char, Width * Height> m_maptip;
};

#endif
