//
// Created by juan.castellanos on 9/07/20.
//

#ifndef STARTER_CPP_FOO_HXX
#define STARTER_CPP_FOO_HXX

// Windows only

#include "IFoo.hpp"

struct Foo : IFoo
{
  void doSomething() override;
};

#endif  //STARTER_CPP_FOO_HXX
