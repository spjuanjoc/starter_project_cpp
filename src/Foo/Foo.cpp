#include "Foo/Foo.hpp"

bool Bar::runDoSomething(IFoo& iFoo)
{
  iFoo.doSomething();
  _done = true;
  return true;
}
