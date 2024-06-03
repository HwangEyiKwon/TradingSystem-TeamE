#pragma once

#include <string>
#define interface struct

using std::string;

interface StockBrockerDriverInterface {
	virtual bool login(string str1, string str2) = 0;
	virtual bool buy(string stockCode, int amount, int price) = 0;
	virtual bool sell(string stockCode, int amount, int price) = 0;
	virtual int getCurrentPrice(string stockCode) = 0;
};