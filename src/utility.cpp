/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include "utility.hpp"

std::vector<std::string>
split(std::string const& input, char del) {
    std::istringstream is{input};
    std::vector<std::string> result;
    std::string buf;
    while (std::getline(is, buf, del))
        result.push_back(buf);
    return result;
}

