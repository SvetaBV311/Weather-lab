#include "Tools.h"
#include<string>

using json = nlohmann::json;


void Tools::showFiveDaysForecast(const json& data) {
	std::cout << std::endl;
	int index = 0, counter, index_2; float sum; std:: string date, date2;
	while (index < data["list"].size()) {
		date = data["list"][index]["dt_txt"];
		date.erase(10);
		index_2 = index + 1;
		date2 = data["list"][index_2]["dt_txt"];
		date2.erase(10);
		counter = 1; sum = data["list"][index]["main"]["temp"];
		while (date2 == date) {
			counter += 1;
			sum += data["list"][index_2]["main"]["temp"];
			index_2 += 1;
			if (index_2 >= data["list"].size()) { break; }
			date2 = data["list"][index_2]["dt_txt"];
			date2.erase(10);
		}
		std::cout << date << " Temp: ";
		if (sum / counter - 273.15 > 0) {
			std::cout << "+";
		}
		std::cout << std::setprecision(1) << std::fixed;
		std::cout << sum / counter - 273.15 << "°C" << std::endl;
		index = index_2;
	}
}

void Tools::showOneDayWeather(const json& data, const std::string& ndate) {
	std::cout << std::endl;
	int counter = 0; float sum = 0; std::string date;
	for (int index = 0; index < data["list"].size(); index++) {
		date = data["list"][index]["dt_txt"];
		date.erase(10);
		if (ndate == date) {
			counter += 1;
			sum += data["list"][index]["main"]["temp"];
		}
	}
	std::cout << ndate << " Temp: ";
	if (sum / counter - 273.15 > 0) {
		std::cout << "+";
	}
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << sum / counter - 273.15 << "°C" << std::endl;
}

void Tools::showCurrentWeather(const json& data) {
	std::cout << std::endl;
	std::cout << "Current weather: " << data["weather"][0]["main"] << std::endl << "Temp: ";
	if (data["main"]["temp"] - 273.15 > 0) {
		std::cout << "+";
	}
	std::cout << data["main"]["temp"] - 273.15 << "°C" << ", feels like: ";
	if (data["main"]["feels_like"] - 273.15 > 0) {
		std::cout << "+";
	}
	std::cout << data["main"]["feels_like"] - 273.15 << "°C" << std::endl;
}

void Tools::showMenu() {
	std::cout << std::endl << "Выберите опцию: " << std::endl;
	std::cout << "1 - Узнать погоду на данный момент;" << std::endl;
	std::cout << "2 - Посмотреть прогноз погоды на 5 дней;" << std::endl;
	std::cout << "3 - Посмотреть прогноз погоды на конкретный день из ближайших 5 дней;" << std::endl;
	std::cout << "4 - Выход." << std::endl;
}