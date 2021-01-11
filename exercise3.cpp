#include <iostream>

// Takes a string and returns a boolean value denoting whether the string contains only numeric characters. 
// Used to validate inputs before they are converted to the correct type.
bool isNumeric(std::string input) {
  std::string numericChars = "0123456789.-";
  for (char c : input) {
    if (numericChars.find(c) == std::string::npos) {
      return false;
    }
  }
  try {
    stod(input);
  } catch (std::out_of_range) {
    return false;
  }
  return true;
}

int main() {
  const double feetToMetersRatio = 0.3048; // 1 foot is 0.3048 meters
  std::string lengthString, widthString;
  double length, width;

  std::cout << "What is the length of the room in feet? ";
  std::cin >> lengthString;
  while (!isNumeric(lengthString)) {
    std::cout << "Invalid length. Please enter a numeric value: ";
    std::cin >> lengthString;
  }
  length = stod(lengthString);

  std::cout << "What is the width of the room in feet? ";
  std::cin >> widthString;
  while (!isNumeric(widthString)) {
    std::cout << "Invalid width. Please enter a numeric value: ";
    std::cin >> widthString;
  }
  width = stod(widthString);

  double areaInFeet = length * width;
  double areaInMeters = length * feetToMetersRatio * width * feetToMetersRatio;
  std::cout 
    << "Your room's dimension is " << length << " by " << width << " feet, the area is:\n" 
    << areaInFeet << " square foot\n"
    << areaInMeters << " square meters" << std::endl;
}
