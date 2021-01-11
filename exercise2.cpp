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

void outputKeyPrompt(std::string fromOrTo) {
  char scaleKeys[] = {'C', 'F', 'K'};
  std::string scales[] = {"Centigrade", "Fahrenheit", "Kelvin"};

  for (int index = 0; index < 3; index++) {
    std::cout << "Press ‘" << scaleKeys[index] << "’ to convert " << fromOrTo << " " << scales[index] << "\n";
  }
}

int main() {
  float startingTemp;
  char choiceFrom;
  char choiceTo;

  std::cout << "Please enter the starting temperature: ";
  std::cin >> startingTemp;
  outputKeyPrompt("from");
  std::cin >> choiceFrom;
  std::cout << "Your choice: " << choiceFrom << std::endl;
  outputKeyPrompt("to");
  std::cin >> choiceTo;
  std::cout << "Converting to: " << choiceTo << std::endl;

  TemperatureConverter temperatureConverter = TemperatureConverter(startingTemp, choiceFrom);
  std::cout << startingTemp << "°" << choiceFrom << " is " << temperatureConverter.convert(choiceTo) << "°" << choiceTo;
}
