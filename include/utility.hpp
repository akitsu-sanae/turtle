/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef TURTLE_UTILITY_HPP
#define TURTLE_UTILITY_HPP

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(std::string const&, char);

template<typename T>
inline T clamp(T const& x, T const& n) {
    if (x < -n)
        return -n;
    if (x > n)
        return n;
    return x;
}

template<typename T>
inline T clamp(T const& x, T const& min, T const& max) {
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}

#endif
