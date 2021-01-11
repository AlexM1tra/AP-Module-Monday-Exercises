#include <iostream>

bool isEven(char digit) {
  std::string evens = "02468";
  if (evens.find(digit) != std::string::npos) {
    return true;
  }
  return false;
}

char lastDigit(std::string number) {
  return number[number.size()-1]; 
}

int main() {
  std::string number;
  std::cout << "Please enter a value? ";
  std::cin >> number;
  if (isEven(lastDigit(number))) {
    std::cout << number << " is an even number" << std::endl;
  } else {
    std::cout << number << " is an odd number" << std::endl;
  }
  return 0;
}
