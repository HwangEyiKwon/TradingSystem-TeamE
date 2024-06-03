#include "AutoTradingSystem.h"

AutoTradingSystem::AutoTradingSystem(StockBrockerDriverInterface* _driver)
	: driver(_driver) {}

bool AutoTradingSystem::login(string id, string pwd) {
	return true;
}