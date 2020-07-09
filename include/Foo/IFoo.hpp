//
// Created by juan.castellanos on 9/07/20.
//

#ifndef STARTER_CPP_IFOO_H
#define STARTER_CPP_IFOO_H

// Common for all the platforms

struct IFoo
{
  virtual ~IFoo() = default;

  virtual void doSomething() = 0;
};

#endif  //STARTER_CPP_IFOO_H
