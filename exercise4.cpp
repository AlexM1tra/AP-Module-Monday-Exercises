#include <iostream>

int main() {
  int number;
  std::cout << "Please enter a value? ";
  std::cin >> number;
  if (number % 2 == 0) {
    std::cout << number << " is an even number" << std::endl;
  } else {
    std::cout << number << " is an odd number" << std::endl;
  }
  return 0;
}
