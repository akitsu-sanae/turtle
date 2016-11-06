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

    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight,

    Invalid
};

template<OpType> struct Operation;

struct OperationBase {
    static std::unique_ptr<OperationBase> read(std::string const&);
    virtual OpType type() const = 0;

    template<OpType T>
    Operation<T> const& cast() const;
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

// move operations
template<OpType T>
struct Operation : public OperationBase {
    explicit Operation(int n) :
        distance(n)
    {}
    OpType type() const override {
        return T;
    }
    int distance;
};

inline std::unique_ptr<OperationBase> OperationBase::read(std::string const& command) {
    auto args = split(command, ' ');
    if (args.size() == 1) {
        if (args[0] == "quit")
            return std::make_unique<Operation<OpType::Quit> >();
        else
            return std::make_unique<Operation<OpType::Invalid> >();
    } else if (args.size() == 2) {
        if (args[0] == "up")
            return std::make_unique<Operation<OpType::MoveUp> >(std::stoi(args[1]));
        else if (args[0] == "down")
            return std::make_unique<Operation<OpType::MoveDown> >(std::stoi(args[1]));
        else if (args[0] == "left")
            return std::make_unique<Operation<OpType::MoveLeft> >(std::stoi(args[1]));
        else if (args[0] == "right")
            return std::make_unique<Operation<OpType::MoveRight> >(std::stoi(args[1]));
        else if (args[0] == "load")
            return std::make_unique<Operation<OpType::Load> >(args[1]);
        else
            return std::make_unique<Operation<OpType::Invalid> >();
    } else
        return std::make_unique<Operation<OpType::Invalid> >();
}

template<OpType T>
inline Operation<T> const& OperationBase::cast() const {
    return dynamic_cast<Operation<T> const&>(*this);
}


#endif
