#include <iostream>

int main() {
  const double feetToMetersRatio = 0.3048;
  double length;
  double width;
  std::cout << "What is the length of the room in feet? ";
  std::cin >> length;
  std::cout << "What is the width of the room in feet? ";
  std::cin >> width;
  double areaInFeet = length * width;
  double areaInMeters = length * feetToMetersRatio * width * feetToMetersRatio;
  std::cout 
    << "You room's dimension is " << length << " by " << width << " feet, the area is:\n" 
    << areaInFeet << " square foot\n"
    << areaInMeters << " square meters" << std::endl;
}
