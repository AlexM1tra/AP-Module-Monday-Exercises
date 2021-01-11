#include <iostream>

int main() {
  int age;
  int restingPulse;
  std::cout << "Please enter your age: ";
  std::cin >> age;
  std::cout << "Please enter your resting pulse: ";
  std::cin >> restingPulse;
  std::cout << "Resting Pulse: " << restingPulse << " Age: " << age << std::endl << "Intensity Rate\n------------------------------\n";
  int targetHR;
  for (int rate = 40; rate < 96; rate += 5) {
    targetHR = (((220 - age) - restingPulse) * rate/100) + restingPulse;
    //TargetHR = ( ( ( 220 – Age ) – RestingHR ) * %intensity ) + RestingHR;
    std::cout << rate << "%.\t\t" << targetHR << " bpm\n";
  }
}
