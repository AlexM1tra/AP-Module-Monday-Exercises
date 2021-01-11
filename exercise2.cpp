#include <iostream>

class TemperatureConverter {
  private:
    float startingTempC;
    float startingTempF;
    float startingTempK;

    void createTempsFromC(float temperature) {
      this->startingTempC = temperature;
      this->startingTempF = (temperature * 9 / 5) + 32;
      this->startingTempK = temperature + 273.15;
    }

    void createTempsFromF(float temperature) {
      createTempsFromC((temperature - 32) * 5 / 9);
    }

    void createTempsFromK(float temperature) {
      createTempsFromC(temperature - 273.15);
    }

  public:
    TemperatureConverter(float startingTemperature, char startingTemperatureKey) {
      startingTemperatureKey = toupper(startingTemperatureKey);
      if (startingTemperatureKey == 'C') {
        createTempsFromC(startingTemperature);
      } else if (startingTemperatureKey == 'F') {
        createTempsFromF(startingTemperature);
      } else if (startingTemperatureKey == 'K') {
        createTempsFromK(startingTemperature);
      } else {
        throw std::invalid_argument("Original temperature key is invalid");
      }
    }

    float convert(char temperatureKey) {
      temperatureKey = toupper(temperatureKey);
      if (temperatureKey == 'C') {
        return startingTempC;
      } else if (temperatureKey == 'F') {
        return startingTempF;
      } else if (temperatureKey == 'K') {
        return startingTempK;
      }
      throw std::invalid_argument("Target temperature key is invalid");
    }
};

bool isNumeric(std::string input) {
  std::string numericChars = "0123456789.-";
  for (char c : input) {
    if (numericChars.find(c) == std::string::npos) {
      return false;
    }
  }
  try {
    stof(input);
  } catch (std::out_of_range) {
    return false;
  }
  return true;
}

void outputKeyPrompt(std::string fromOrTo) {
  char scaleKeys[] = {'C', 'F', 'K'};
  std::string scales[] = {"Centigrade", "Fahrenheit", "Kelvin"};

  for (int index = 0; index < 3; index++) {
    std::cout << "Press ‘" << scaleKeys[index] << "’ to convert " << fromOrTo << " " << scales[index] << "\n";
  }
}

char getChoice() {
  std::string choice;
  std::cin >> choice;
  while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'F' && toupper(choice[0]) != 'K') {
    std::cout << "Invalid choice. Please choose either 'C', 'F' or 'K'.\n";
    std::cin >> choice;
  }
  return choice[0];
}

int main() {
  std::string startingTempString;
  float startingTemp;

  std::cout << "Please enter the starting temperature: ";
  std::cin >> startingTempString;
  while (!isNumeric(startingTempString)) {
    std::cout << "Invalid temperature. Please enter a numeric temperature.\n";
    std::cin >> startingTempString;
  }
  startingTemp = stof(startingTempString);
  outputKeyPrompt("from");
  char choiceFrom = getChoice();
  std::cout << "Your choice: " << choiceFrom << std::endl;
  outputKeyPrompt("to");
  char choiceTo = getChoice();
  std::cout << "Converting to: " << choiceTo << std::endl;

  TemperatureConverter temperatureConverter = TemperatureConverter(startingTemp, choiceFrom);
  std::cout << startingTemp << "°" << toupper(choiceFrom) << " is " << temperatureConverter.convert(toupper(choiceTo)) << "°" << choiceTo << std::endl;
}
