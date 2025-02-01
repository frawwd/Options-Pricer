#pragma once

#include "include.h"

namespace util {
	double normalCDF(double x) // Phi(-∞, x) aka N(x)
	{
		return erfc(-x / std::sqrt(2)) / 2;
	}
}