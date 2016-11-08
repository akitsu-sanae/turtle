/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>
#include <memory>
#include <fstream>

#include "command_loader.hpp"
#include "operation.hpp"

std::unique_ptr<OperationBase>
CommandLoader::read() {
    std::string command;
    while (!files.empty() && !files.back())
        files.pop_back();

    if (files.empty())
        std::getline(std::cin, command);
    else
        std::getline(files.back(), command);
    return OperationBase::read(command);
}

void CommandLoader::new_file(std::string const& filename) {
    std::ifstream ifs(filename);
    files.push_back(std::move(ifs));
}

