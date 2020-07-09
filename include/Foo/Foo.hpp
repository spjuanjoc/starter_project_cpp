//
// Created by juan.castellanos on 9/07/20.
//

#ifndef STARTER_CPP_FOO_H
#define STARTER_CPP_FOO_H

// Cross-platform

#include "IFoo.hpp"

struct Foo : IFoo
{
  void runDoSomething();

protected:
  void doSomething() override;
};

#endif  //STARTER_CPP_FOO_H
