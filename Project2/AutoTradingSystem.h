#pragma once
#include "StockBrockerDriverInterface.h"

class AutoTradingSystem {
public:
	AutoTradingSystem(StockBrockerDriverInterface* _driver);

	bool login(string id, string pwd);

private:
	StockBrockerDriverInterface* driver;
};