/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_COMMAND_LOADER_HPP
#define TURTLE_COMMAND_LOADER_HPP

#include <vector>

struct OperationBase;

struct CommandLoader {
    std::unique_ptr<OperationBase> read();
    void new_file(std::string const&);
private:
    std::vector<std::ifstream> files;
};

#endif

