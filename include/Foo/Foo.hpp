//
// Created by juan.castellanos on 9/07/20.
//

#ifndef STARTER_CPP_FOO_HPP
#define STARTER_CPP_FOO_HPP

// Cross-platform

#include "IFoo.hpp"

struct Foo : IFoo
{
  void doSomething() override;
  ~Foo() override = default;
};

struct Bar
{
//  IFoo& _iFoo;
  bool _done;
  bool runDoSomething(IFoo& iFoo);
};

#endif  //STARTER_CPP_FOO_HPP
