#include <iostream>

int main() {
  char character;
  std::cout << "Please enter a character? ";
  std::cin >> character;
  if (isalpha(character)) {
    std::cout << "Alphabetic character detected.\n";
  } else if (isdigit(character)) {
    std::cout << "Digit character detected.\n";
  } else {
    std::cout << "Special character detected.\n";
  }
  char tryAgain;
  std::cout << "Try again (y/N)? ";
  std::cin >> tryAgain;
  if (toupper(tryAgain) != 'Y') {
    std::cout << "Thank you, good bye.\n";
  } else {
    main();
  }
}
