#ifndef TURTLE_UTILITY_HPP
#define TURTLE_UTILITY_HPP

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(std::string const& input, char del) {
    std::istringstream is{input};
    std::vector<std::string> result;
    std::string buf;
    while (std::getline(is, buf, del))
        result.push_back(buf);
    return result;
}

template<typename T>
T clamp(T const& x, T const& n) {
    if (x < -n)
        return -n;
    if (x > n)
        return n;
    return x;
}

#endif
