#include "option.h"

#include "include.h"
#include "util.h"

void Option::calc_d1() {
	d1 = log(current_asset_price / strike_price) + (risk_free_intrest + std::pow(volatility, 2) / 2) * time_to_maturity;
	d1 = d1 / volatility * std::sqrt(time_to_maturity);
}

void Option::calc_d2() {
	d2 = d1 - volatility * std::sqrt(time_to_maturity);
}

void Option::calc_call_price() {
	call_price = current_asset_price * util::normalCDF(d1) - strike_price * std::exp(-risk_free_intrest * time_to_maturity) * util::normalCDF(d2);
	if (call_price < 0) call_price = 0;
}

void Option::calc_put_price() {
	put_price = strike_price * std::exp(-risk_free_intrest * time_to_maturity) * util::normalCDF(-d2) - current_asset_price * util::normalCDF(-d1);
	if (put_price < 0) put_price = 0;
}