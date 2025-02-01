#pragma once

class Option {
public:
	void calc_d1();
	void calc_d2();

	void calc_call_price();
	void calc_put_price();

	float call_price;
	float put_price;

	float current_asset_price = 100.00f;
	float strike_price = 100.00f;
	float time_to_maturity = 1.00f;
	float volatility = 0.20f;
	float risk_free_intrest = 0.05;
private:
	float d1;
	float d2;
};
