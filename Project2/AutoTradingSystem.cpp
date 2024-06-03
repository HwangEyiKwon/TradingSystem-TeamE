#include "AutoTradingSystem.h"
#include <stdexcept>

class LoginIdNullException : public std::exception {
	char const* what() const override {
		return "Login ID should be entered";
	}
};

class LoginPwdNullException : public std::exception {
	char const* what() const override {
		return "Login PWD should be entered";
	}
};

AutoTradingSystem::AutoTradingSystem(StockBrockerDriverInterface* _driver)
	: driver(_driver) {}

bool AutoTradingSystem::login(string id, string pwd) {
	if (id == "")
		throw LoginIdNullException();
	if (pwd == "")
		throw LoginPwdNullException();
	return driver->login(id, pwd);
}