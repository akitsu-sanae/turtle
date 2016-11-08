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

    TurnLeft,
    TurnRight,
    Forward,
    Backward,

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
struct Operation<OpType::TurnLeft> : public OperationBase {
    OpType type() const override { return OpType::TurnLeft; }
};
template<>
struct Operation<OpType::TurnRight> : public OperationBase {
    OpType type() const override { return OpType::TurnRight; }
};

template<>
struct Operation<OpType::Forward> : public OperationBase {
    explicit Operation(int n) :
        distance(n)
    {}
    OpType type() const override { return OpType::Forward; }
    int distance;
};
template<>
struct Operation<OpType::Backward> : public OperationBase {
    explicit Operation(int n) :
        distance(n)
    {}
    OpType type() const override { return OpType::Backward; }
    int distance;
};



#endif
