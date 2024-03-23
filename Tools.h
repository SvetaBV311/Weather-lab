#pragma once
#include <iostream>
#include <nlohmann/json.hpp>


namespace Tools {
	void showFiveDaysForecast(const nlohmann::json& data);
	void showCurrentWeather(const nlohmann::json& data);
	void showOneDayWeather(const nlohmann::json& data, const std::string& ndate);
	void showMenu();
}


