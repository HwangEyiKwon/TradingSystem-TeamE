#include "StockBrockerDriverInterface.h"

class AutoTradingSystem {
public:
	AutoTradingSystem(StockBrockerDriverInterface *mockDriver) :
		_mockDriver(mockDriver) {}

	void buy(string stockCode, int amount, int price) {

	}

private:
	StockBrockerDriverInterface* _mockDriver;
};