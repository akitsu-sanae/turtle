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
        m_dir = static_cast<Direction>((static_cast<int>(m_dir) + 1) % 4);
        break;
    case OpType::TurnRight:
        m_dir = static_cast<Direction>((static_cast<int>(m_dir) - 1 + 4) % 4);
        break;
    case OpType::Forward:
        switch (m_dir) {
        case Direction::Up:
            m_y -= op->cast<OpType::Forward>().distance;
            break;
        case Direction::Down:
            m_y += op->cast<OpType::Forward>().distance;
            break;
        case Direction::Right:
            m_x += op->cast<OpType::Forward>().distance;
            break;
        case Direction::Left:
            m_x -= op->cast<OpType::Forward>().distance;
            break;
        }
        break;
    case OpType::Backward:
        switch (m_dir) {
        case Direction::Up:
            m_y += op->cast<OpType::Backward>().distance;
            break;
        case Direction::Down:
            m_y -= op->cast<OpType::Backward>().distance;
            break;
        case Direction::Right:
            m_x -= op->cast<OpType::Backward>().distance;
            break;
        case Direction::Left:
            m_x += op->cast<OpType::Backward>().distance;
            break;
        }
        break;
    default:
        abort();
    }
    track.coords.emplace_back(m_x, m_y);
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


