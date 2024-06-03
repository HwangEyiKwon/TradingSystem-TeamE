#include "AutoTradingSystem.h"
#include <stdexcept>

AutoTradingSystem::AutoTradingSystem(StockBrockerDriverInterface* _driver)
	: driver(_driver) {}

bool AutoTradingSystem::login(string id, string pwd) {
	if (id == "") throw std::invalid_argument("id should be entered");
	if (pwd == "") throw std::invalid_argument("pwd should be entered");
	return true;
}