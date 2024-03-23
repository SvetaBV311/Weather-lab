#include <iostream>
#include "WeatherApp.h"
#include "Tools.h"

using namespace Tools;

const std::string API = "e566abb4bf71c63f4750ec1a847e21c8";


void main() {	
	using json = nlohmann::json;
	setlocale(LC_ALL, "RUS");

	std::string city, choice; bool bl = true;
	std::cout << "Введите город: ";
	std::cin >> city;

	WeatherApp* app = new WeatherApp("api.openweathermap.org", API, city);

	while (bl) {
		showMenu();
		std::cin >> choice;
		if (choice == "1") {
			showCurrentWeather(app->getCurrentWeather());
		}
		else if (choice == "2") {
			showFiveDaysForecast(app->getWeatherForFiveDays());
		}
		else if (choice == "3") {
			std::cout << std::endl << "До новых встреч!" << std::endl;
			bl = false;
		}
		else {
			std::cout << std::endl << "Неверный выбор, попробуйте еще раз. " << std::endl;
		}
	}
}