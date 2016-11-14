/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include "utility.hpp"
#include "turtle.hpp"
#include "field.hpp"
#include "track.hpp"
#include "operation.hpp"

Turtle::Turtle(Field const& field) :
    m_field(field)
{
}

void Turtle::update(std::unique_ptr<OperationBase> const& op, Track* track) {
    int dir = 0;
    switch (op->type()) {
    case OpType::Turn:
        dir = static_cast<int>(op->cast<OpType::Turn>().dir);
        m_dir = static_cast<Direction>((static_cast<int>(m_dir) + dir + 4) %4);
        break;
    case OpType::Go:
        dir = static_cast<int>(op->cast<OpType::Go>().dir);
        switch (m_dir) {
        case Direction::Up:
            m_y -= op->cast<OpType::Go>().distance * dir;
            break;
        case Direction::Down:
            m_y += op->cast<OpType::Go>().distance * dir;
            break;
        case Direction::Right:
            m_x += op->cast<OpType::Go>().distance * dir;
            break;
        case Direction::Left:
            m_x -= op->cast<OpType::Go>().distance * dir;
            break;
        }
        break;
    default:
        abort();
    }
    m_x = clamp(m_x, 1, (int)m_field.width()-1);
    m_y = clamp(m_y, 1, (int)m_field.height()-1);
    if (track)
        track->put(m_x, m_y);
}

void Turtle::draw() const {
    std::printf("\033[%d;%dH*", m_y, m_x);
    switch (m_dir) {
    case Direction::Up:
        std::printf("\033[%d;%dH^", m_y-1, m_x);
        break;
    case Direction::Left:
        std::printf("\033[%d;%dH<", m_y, m_x-1);
        break;
    case Direction::Down:
        std::printf("\033[%d;%dHV", m_y+1, m_x);
        break;
    case Direction::Right:
        std::printf("\033[%d;%dH>", m_y, m_x+1);
        break;
    }
}


