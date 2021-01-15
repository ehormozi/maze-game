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

class maze_entrance : public field
{
public:

	maze_entrance();

	field_effect effect(const offset2d& o, bool is_sim = true) const override;
	void reveal() override;
};
