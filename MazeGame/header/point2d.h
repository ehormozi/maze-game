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

using coord = int;

struct point2d
{
	point2d() = delete;

	point2d(coord x_in, coord y_in);

	point2d(const point2d& o) = default;

	point2d& operator=(const point2d& o) = default;

	bool operator==(const point2d& o) const;

	bool operator!=(const point2d& o) const;

	bool operator<(const point2d& o) const;

	point2d& operator+=(const offset2d& o);

	point2d& operator-=(const offset2d& o);

	coord x;
	coord y;
};

point2d operator+(const point2d& p, const offset2d& o);
point2d operator+(const offset2d& o, const point2d& p);
point2d operator-(const point2d& p, const offset2d& o);
point2d operator-(const offset2d& o, const point2d& p);
offset2d operator-(const point2d& p1, const point2d& p2);
