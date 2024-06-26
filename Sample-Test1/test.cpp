#include <string>
#include <stdexcept>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Project2/AutoTradingSystem.cpp"
#include "../Project2/StockBrockerDriverInterface.h"

using namespace testing;
using namespace std;

class MockDriver : public StockBrockerDriverInterface
{
public:
	MOCK_METHOD(bool, login, (string str1, string str2), (override));
	MOCK_METHOD(bool, buy, (string stockCode, int amount, int price), (override));
	MOCK_METHOD(bool, sell, (string stockCode, int amount, int price), (override));
	MOCK_METHOD(int, getCurrentPrice, (string stockCode), (override));
};

class TradingSystemFixture : public testing::Test
{
public:
	MockDriver mockDriver;
	AutoTradingSystem tradingSystem{ &mockDriver };
};

// Login
TEST_F(TradingSystemFixture, LoginExceptionTest00) {
	string id = ""; // 빈 id
	string pwd = "pwdpwd";
	
	try {
		tradingSystem.login(id, pwd);
		FAIL();
	}
	catch (exception& e) {
		cout << "Exception occurs: " << e.what() << endl;
	}
}
TEST_F(TradingSystemFixture, LoginExceptionTest01) {
	string id = "hwang.id";
	string pwd = ""; // 빈 pwd

	try {
		tradingSystem.login(id, pwd);
		FAIL();
	}
	catch (exception& e) {
		cout << "Exception occurs: " << e.what() << endl;
	}
}
TEST_F(TradingSystemFixture, LoginNormalTest) {
	string id = "hwang.id";
	string pwd = "pwdpwd";

	EXPECT_CALL(mockDriver, login)
		.Times(1)
		.WillRepeatedly(Return(true));
	EXPECT_TRUE(tradingSystem.login(id, pwd));
}
TEST_F(TradingSystemFixture, LoginFailTest) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	EXPECT_CALL(mockDriver, login)
		.Times(1)
		.WillRepeatedly(Return(false));
	EXPECT_FALSE(tradingSystem.login(id, pwd));
}

// buy
TEST_F(TradingSystemFixture, buyExceptionTest00) {
	string stockCode = "SAMSUNG";
	int amount = 10;
	int price = 75000;

	EXPECT_THROW(tradingSystem.buy(stockCode, amount, price), exception); // 로그인 없이 구매 요청 시 exception
}
TEST_F(TradingSystemFixture, buyExceptionTest01) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	tradingSystem.login(id, pwd);

	string stockCode = "SAAAAAMSUNG"; //잘못된 이름
	int amount = 10;
	int price = 75000;

	EXPECT_THROW(tradingSystem.buy(stockCode, amount, price), exception);
}
TEST_F(TradingSystemFixture, buyExceptionTest02) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	tradingSystem.login(id, pwd);

	string stockCode = "SAMSUNG";
	int amount = -5; // 잘못된 amount
	int price = 75000;

	EXPECT_THROW(tradingSystem.buy(stockCode, amount, price), exception);
}
TEST_F(TradingSystemFixture, buyExceptionTest03) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	tradingSystem.login(id, pwd);

	string stockCode = "SAMSUNG";
	int amount = 10;
	int price = -75000; // 잘못된 price

	EXPECT_THROW(tradingSystem.buy(stockCode, amount, price), exception);
}
TEST_F(TradingSystemFixture, buyNormalTest) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	tradingSystem.login(id, pwd);

	string stockCode = "SAMSUNG";
	int amount = 10;
	int price = 75000;

	EXPECT_TRUE(tradingSystem.buy(stockCode, amount, price));
}

// sell
TEST_F(TradingSystemFixture, sellExceptionTest00) {
	string stockCode = "SAMSUNG";
	int amount = 10;
	int price = 75000;

	EXPECT_THROW(tradingSystem.sell(stockCode, amount, price), exception); // 로그인 없이 판매 요청 시 exception
}
TEST_F(TradingSystemFixture, sellExceptionTest01) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	tradingSystem.login(id, pwd);

	string stockCode = "SAAAAAMSUNG"; //잘못된 이름
	int amount = 10;
	int price = 75000;

	EXPECT_THROW(tradingSystem.sell(stockCode, amount, price), exception);
}
TEST_F(TradingSystemFixture, sellExceptionTest02) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	tradingSystem.login(id, pwd);

	string stockCode = "SAMSUNG";
	int amount = -5; // 잘못된 amount
	int price = 75000;

	EXPECT_THROW(tradingSystem.sell(stockCode, amount, price), exception);
}
TEST_F(TradingSystemFixture, sellExceptionTest03) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	tradingSystem.login(id, pwd);

	string stockCode = "SAMSUNG";
	int amount = 10;
	int price = -75000; // 잘못된 price

	EXPECT_THROW(tradingSystem.sell(stockCode, amount, price), exception);
}
TEST_F(TradingSystemFixture, sellNormalTest) {
	string id = "hwang.id";
	string pwd = "pwdpwd";
	tradingSystem.login(id, pwd);

	string stockCode = "SAMSUNG";
	int amount = 10;
	int price = 75000;

	EXPECT_TRUE(tradingSystem.sell(stockCode, amount, price));
}

// getCurrentPrice
TEST_F(TradingSystemFixture, getCurrentPriceExceptionTest) {
	string stockCode = "SAAAAAMSUNG"; // 잘못된 종목 코드
	int expectedPrice = 75000;

	EXPECT_THROW(tradingSystem.getCurrentPrice(stockCode), exception);
}
TEST_F(TradingSystemFixture, getCurrentPriceTest) {
	string stockCode = "SAMSUNG";
	int expectedPrice = 75000;

	EXPECT_THAT(tradingSystem.getCurrentPrice(stockCode), Eq(expectedPrice));
}

// selectStockBrocker
TEST_F(TradingSystemFixture, selectStockBrockerTest00)
{
	KiwerDriver kiwerDriver;
	string selectBrockerName = "Kiwer";
	tradingSystem.selectStockBrocker(selectBrockerName, &kiwerDriver);
	EXPECT_THAT(tradingSystem.getCurrentStockBrockerName(), Eq("Kiwer"));
}
TEST_F(TradingSystemFixture, selectStockBrockerTest01)
{
	NemoDriver nemoDriver;
	string selectBrockerName = "Nemo";
	tradingSystem.selectStockBrocker(selectBrockerName, &nemoDriver);
	EXPECT_THAT(tradingSystem.getCurrentStockBrockerName(), Eq("Nemo"));
}

// buyNiceTiming
TEST_F(TradingSystemFixture, buyNiceTimingTest)
{
	string stockCode = "SAMSUNG";
	int price = 75000;

	EXPECT_CALL(mockDriver, getCurrentPrice(stockCode)).Times(3)
														.WillOnce(Return(50000))
														.WillOnce(Return(65000))
														.WillOnce(Return(75000))
														.WillRepeatedly(Return(77000));

	tradingSystem.buyNiceTiming(stockCode, price);
}

// sellNiceTiming
TEST_F(TradingSystemFixture, sellNiceTimingTest)
{
	string stockCode = "SAMSUNG";
	int price = 50000;

	EXPECT_CALL(mockDriver, getCurrentPrice(stockCode)).Times(3)
														.WillOnce(Return(75000))
														.WillOnce(Return(65000))
														.WillOnce(Return(50000))
														.WillRepeatedly(Return(45000));

	tradingSystem.sellNiceTiming(stockCode, price);
}