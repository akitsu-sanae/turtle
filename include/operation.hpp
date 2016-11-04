/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_OPERATION_HPP
#define TURTLE_OPERATION_HPP

struct Operation {
    enum class Type {
        Quit,

        MoveUp,
        MoveDown,
        MoveLeft,
        MoveRight,

        Invalid
    };

    Type type;

    static Type to_type(std::string const& str) {
        if (str == "quit")
            return Type::Quit;
        else if (str == "up")
            return Type::MoveUp;
        else if (str == "down")
            return Type::MoveDown;
        else if (str == "left")
            return Type::MoveLeft;
        else if (str == "right")
            return Type::MoveRight;
        else
            return Type::Invalid;
    }
};


#endif
