#include <iostream>

int main() {
  std::string quote;
  std::string author;

  std::cout << "What is the quote?" << std::endl;
  std::getline(std::cin, quote);
  std::cout << "Who said this quote?" << std::endl;
  std::getline(std::cin, author);

  std::cout << author << " said \"" << quote << "\"\n";
}
