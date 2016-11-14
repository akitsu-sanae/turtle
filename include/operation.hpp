/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_OPERATION_HPP
#define TURTLE_OPERATION_HPP

#include <memory>

#include "utility.hpp"

enum class OpType {
    Quit,
    Load,
    Sleep,

    Turn,
    Go,

    Pen,

    Invalid
};

template<OpType> struct Operation;

struct OperationBase {
    static std::unique_ptr<OperationBase> read(std::string const&);
    virtual OpType type() const = 0;

    template<OpType T>
    Operation<T> const& cast() const {
        return dynamic_cast<Operation<T> const&>(*this);
    }
};

template<>
struct Operation<OpType::Quit> : public OperationBase {
    OpType type() const override { return OpType::Quit; }
};
template<>
struct Operation<OpType::Invalid> : public OperationBase {
    OpType type() const override { return OpType::Invalid; }
};

template<>
struct Operation<OpType::Load> : public OperationBase {
    explicit Operation(std::string const& filename) :
        filename(filename)
    {}
    OpType type() const override { return OpType::Load; }
    std::string filename;
};

template<>
struct Operation<OpType::Sleep> : public OperationBase {
    explicit Operation(int n) :
        time(n)
    {}
    OpType type() const override { return OpType::Sleep; }
    int time;
};

template<>
struct Operation<OpType::Turn> : public OperationBase {
    enum class Dir {
        Left = -1,
        Right = 1
    };
    Dir dir;
    explicit Operation(Dir dir) : dir(dir) {}
    OpType type() const override { return OpType::Turn; }
};

template<>
struct Operation<OpType::Go> : public OperationBase {
    enum class Dir {
        Forward = 1,
        Backward = -1
    };
    Dir dir;
    int distance = 0;
    explicit Operation(Dir dir, int d) : dir(dir), distance(d) {}
    OpType type() const override { return OpType::Go; }
};

template<>
struct Operation<OpType::Pen> : public OperationBase {
    enum class Action {
        Up,
        Down
    };
    Action action;
    explicit Operation(Action action) : action(action) {}
    OpType type() const override { return OpType::Pen; }
};

#endif
