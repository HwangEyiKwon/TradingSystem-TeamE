#include <string>
#include "NemoAPI.cpp"
#include "StockBrockerDriverInterface.h"

using namespace std;

class NemoDriver : public StockBrockerDriverInterface {
public:
	NemoDriver(NemoAPI nemoApi) :
		_nemoApi(nemoApi) {}

	bool login(string str1, string str2) {}
	bool buy(string stockCode, int amount, int price) {
		if (IsValidOrder(stockCode, amount, price) == false)
			return false;

		_nemoApi.purchasingStock(stockCode, amount, price);

		return true;
	}
	bool sell(string stockCode, int amount, int price) {}
	int getCurrentPrice(string stockCode) {}

private:
	NemoAPI _nemoApi;
};
