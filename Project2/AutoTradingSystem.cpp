#include "StockBrockerDriverInterface.h"

class AutoTradingSystem {
public:
	AutoTradingSystem(StockBrockerDriverInterface *mockDriver) :
		_mockDriver(mockDriver) {}

	bool login(string str1, string str2) {
		return true;
	}
	bool buy(string stockCode, int amount, int price) {
		_mockDriver->buy(stockCode, amount, price);

		return true;
	}
	bool sell(string stockCode, int amount, int price) {
		return true;
	}
	int getCurrentPrice(string stockCode) {
		return 0;
	}

private:
	StockBrockerDriverInterface* _mockDriver;
};