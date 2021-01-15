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

using coord = int;

struct offset2d
{
	offset2d() = delete;

	offset2d(coord dx_in, coord dy_in);

	offset2d(const offset2d& o) = default;

	offset2d& operator=(const offset2d& o) = default;

	bool operator==(const offset2d& o) const;

	bool operator!=(const offset2d& o) const;

	bool operator<(const offset2d& o) const;

	offset2d& operator+=(const offset2d& o);

	offset2d& operator-=(const offset2d& o);

	offset2d operator+(const offset2d& other) const;

	offset2d operator-(const offset2d& other) const;

	coord dx;
	coord dy;
};
