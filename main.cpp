#include <iostream>
#include <iomanip>
#include <string>
#include <memory>

int main() {
  std::cout << "Hello World!" << std::endl;
  std::unique_ptr<std::string> s_p(new std::string("Greeting"));

  std::cout << *s_p << std::endl;
  std::cout << (s_p ? "true" : "false") << std::endl;
  s_p.release();
  std::cout << (s_p ? "true" : "false") << std::endl;

  return 0;
}
