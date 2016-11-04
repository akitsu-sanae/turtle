/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/turtle
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>

#include "field.hpp"

int main() {
    Field<50, 25> field;
    while (!field.is_quit()) {
        field.draw();
        field.update();
    }
}

