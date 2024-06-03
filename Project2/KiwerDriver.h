#pragma once

#include "StockBrockerDriverInterface.h"

class KiwerDriver : public StockBrockerDriverInterface {
public:
	bool login(string str1, string str2) override;
	bool buy(string stockCode, int amount, int price) override;
	bool sell(string stockCode, int amount, int price) override;
	int getCurrentPrice(string stockCode) override;
};