//
// Created by juan.castellanos on 9/07/20.
//

#ifndef STARTER_CPP_FOO_H
#define STARTER_CPP_FOO_H

// Apple only

#include "IFoo.hpp"
#include <cstdio>

struct Foo : IFoo
{
  void doSomething() override
  {
    puts("Do something from apple");
  }
};

#endif  //STARTER_CPP_FOO_H
