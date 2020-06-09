#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <utility>
#include <type_traits>
#include <typeinfo>
#include <cxxabi.h>

//  MARK: - References.
//  @see: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new/28841507

/*
 *  MARK: main()
 */
int main() {
  std::cout << "Hello World!" << std::endl;
  std::unique_ptr<std::string> s_p(new std::string("Greeting"));

  std::cout << *s_p << std::endl;
  std::cout << (s_p ? "true" : "false") << std::endl;
  s_p.release();
  std::cout << (s_p ? "true" : "false") << std::endl;


  size_t const M = 2;
  size_t const N = 2;

  std::cout << std::endl;

  // allocate (no initializatoin)
  auto array = new double[M][N];

  // pollute the memory
  array[0][0] = 2;
  array[1][0] = 3;
  array[0][1] = 4;
  array[1][1] = 5;

  for (size_t r = 0; r < M; ++r) {
    for (size_t c = 0; c < N; ++c) {
      std::cout << "array[" << r << "][" << c << "]: "
                << array[r][c]
                << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // re-allocate, probably will fetch the same memory block
  // (not portable)
  delete [] array;
  array = new double[M][N];

  // show that memory is not initialized
  for (size_t r = 0; r < M; ++r) {
    for (size_t c = 0; c < N; ++c) {
      std::cout << "array[" << r << "][" << c << "]: "
                << array[r][c]
                << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // the proper way to zero-initialize the array
  array = new double[M][N]();

  // show the memory is initialized
  for (size_t r = 0; r < M; ++r) {
    for (size_t c = 0; c < N; ++c) {
      std::cout << "array[" << r << "][" << c << "]: "
                << array[r][c]
                << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  int info;
  std::cout << abi::__cxa_demangle(typeid(array).name(), 0, 0, &info)
            << std::endl;

  delete [] array;

  return 0;
}
