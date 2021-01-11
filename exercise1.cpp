#include <iostream>

int main() {
  std::string quote;
  std::string author;

  std::cout << "What is the quote? ";
  std::getline(std::cin, quote);
  std::cout << "Who said it? ";
  std::getline(std::cin, author);

  std::cout << author << " says: \"" << quote << "\"\n";
  return 0;
}
