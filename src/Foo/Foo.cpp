#include "Foo/Foo.hpp"

bool Bar::runDoSomething()
{
  _iFoo.doSomething();
  _done = true;
  return true;
}

Bar::Bar(IFoo& iFoo) : _iFoo(iFoo)
{
}
