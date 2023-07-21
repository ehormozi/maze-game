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

#include "offset_2d.h"
#include "field_effect.h"

class field;

using field_ptr = std::shared_ptr<field>;

class field
{
public:

	field(char c);

	virtual ~field();

	char to_char() const;

	void set(char c) const;

	virtual field_effect effect(const offset2d& o, bool is_sim = true) const = 0;

	field_effect effect() const;

	virtual void reveal() = 0;

private:

	mutable char c_;
};

field_ptr to_field(char c);
