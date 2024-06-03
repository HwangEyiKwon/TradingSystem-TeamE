#pragma once
#include <string>

using namespace std;

class StockBrockerDriverInterface {
public:
	virtual bool login(string str1, string str2) = 0;
	virtual bool buy(string stockCode, int amount, int price) = 0;
	virtual bool sell(string stockCode, int amount, int price) = 0;
	virtual int getCurrentPrice(string stockCode) = 0;

	bool IsValidOrder(string stockCode, int amount, int price) {
		if (stockCode != "SAMSUNG")
			throw std::exception("Invalid StockCode");
		if (amount < 0)
			throw std::exception("Invalid amount");
		if (price < 0)
			throw std::exception("Invalid price");

		return true;
	}
};
