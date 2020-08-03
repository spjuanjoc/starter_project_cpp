#include "Foo/Foo.hpp"
#include <functional>
#include <iostream>
#include <map>

void foo()
{
  Foo f{};
  Bar b{f};
  b.runDoSomething();
}

int main()
{
  // weird lambda
  [out = std::ref(std::cout << "Hello ")]() { out.get() << "World\n"; }();

  // string view
  std::map<std::uint32_t, std::string_view> m{{1, "one"}, {2, "two"}, {3, "three"}};

  //Structured binding
  for (const auto& [key, value] : m)
  {
    std::cout << "Key: " << key << " Value: " << value << "\n";
  }

  foo();
}
