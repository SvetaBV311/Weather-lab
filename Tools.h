#pragma once
#include <iostream>
#include <nlohmann/json.hpp>


namespace Tools {
	void showFiveDaysForecast(const nlohmann::json& data);
	void showCurrentWeather(const nlohmann::json& data);
	void showMenu();
}


