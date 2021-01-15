#pragma once

#include <iterator>
#include <cassert>
#include <memory>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

#include "field.h"

class large_trap : public  field
{
public:

	large_trap();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
	void reveal() override;
};
