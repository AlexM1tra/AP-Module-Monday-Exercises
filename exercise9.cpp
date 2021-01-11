#include <iostream>

// Validates user's input and returns valid char.
char charInput() {
  std::string input;
  std::cin >> input;
  while (input.size() > 1) {
    std::cout << "Please enter only one character at a time: ";
    std::cin >> input;
  }
  return input[0];
}

int main() {
  char character, tryAgain;
  do {
    std::cout << "Please enter a character? ";
    character = charInput();
    if (isalpha(character)) {
      std::cout << "Alphabetic character detected.\n";
    } else if (isdigit(character)) {
      std::cout << "Digit character detected.\n";
    } else {
      std::cout << "Special character detected.\n";
    }
    std::cout << "Try again (Y/N)? ";
    tryAgain = charInput();
  } while (toupper(tryAgain) == 'Y');
}
