//
// Created by juan.castellanos on 9/07/20.
//

#ifndef STARTER_CPP_FOO_H
#define STARTER_CPP_FOO_H

// Linux only

#include "IFoo.hpp"
#include <cstdio>

struct Foo : IFoo
{
  void doSomething() override;
};

#endif  //STARTER_CPP_FOO_H
