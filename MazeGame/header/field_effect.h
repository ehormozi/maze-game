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

enum class field_state
{
	NONE = 0,
	FREE,
	DAMAGING,
	ENTRANCE,
	EXIT,
	DEADLY,
	BLOCKED,
};

struct field_effect
{
	field_effect& operator+=(const field_effect& other);

	bool operator!=(const field_effect& rhs);

	field_state state = field_state::NONE;

	unsigned damage = 0;
};

