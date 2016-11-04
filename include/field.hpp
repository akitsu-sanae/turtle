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
        std::string command;
        std::cin >> command;
        auto op = Operation::to_type(command);
        switch (op) {
        case Operation::Type::Quit:
            m_is_quit = true;
            break;
        case Operation::Type::MoveUp:
        case Operation::Type::MoveDown:
        case Operation::Type::MoveLeft:
        case Operation::Type::MoveRight:
            turtle.update(op);
            break;
        case Operation::Type::Invalid:
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
                std::cout << at(x, y);
            }
            std::cout << std::endl;
        }
        turtle.draw();
        std::printf("\033[%d;1HCommand: ", Height);
    }

    char at(size_t x, size_t y) const {
        return m_maptip.at(x + y*Width);
    }
    bool is_quit() const { return m_is_quit; }
private:
    bool m_is_quit = false;
    std::array<char, Width * Height> m_maptip;
};

#endif
