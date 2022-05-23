#include <aop/mcaspect.hpp>
#include <iostream>
namespace data {
namespace model {
struct Data {
public:
  int model;

public:
  int a;
  int b;
  int c;
};
}; // namespace model
}; // namespace data

struct Log {
  void before(const char *str) {
    std::cout << "Log before " << str << std::endl;
  }

  void after(const char *str) { std::cout << "Log after " << str << std::endl; }
};

struct Clock {
  void before(const char *str) {
    std::cout << "Clock before " << str << std::endl;
  }

  void after(const char *str) {
    std::cout << "Clock after " << str << std::endl;
  }
};

struct Lambda {
  void before() { std::cout << "Lambda before " << std::endl; }

  void after() { std::cout << "Lambda after " << std::endl; }
};

void foo(const char *str) { std::cout << str << std::endl; }
// define a function add two numbers
// @param a: the first number
// @param b: the second number
// @return: the sum of a and b
int add(int a, int b) { return a + b; }

int main() {
  mc::make_aspect<Log, Clock>(&foo, "foo function");
  mc::make_aspect<Lambda>([]() { std::cout << "lambda function\n"; });

  return 0;
}
