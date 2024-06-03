#include <string>
#include "KiwerAPI.cpp"
#include "StockBrockerDriverInterface.h"

using namespace std;

class KiwerDriver: public StockBrockerDriverInterface {
public:
	KiwerDriver(KiwerAPI kiwerApi) :
		_kiwerApi(kiwerApi) {}

	bool login(string str1, string str2) {}
	bool buy(string stockCode, int amount, int price) {
		if (IsValidOrder(stockCode, amount, price) == false)
			return false;

		_kiwerApi.buy(stockCode, amount, price);

		return true;
	}
	bool sell(string stockCode, int amount, int price) {}
	int getCurrentPrice(string stockCode) {}

private:
	KiwerAPI _kiwerApi;
};
