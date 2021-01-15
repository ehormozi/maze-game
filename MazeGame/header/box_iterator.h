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

#include "point2d.h"

class box_iterator
{
public:

	using iterator_category = std::forward_iterator_tag;
	using value_type = point2d;
	using difference_type = void;
	using pointer = point2d*;
	using reference = point2d&;

	box_iterator(coord x_beg, coord x_end, coord y_beg, coord y_end);

	box_iterator(const point2d& lower_left, const point2d& upper_right);

	void reset();

	box_iterator& operator++();

	bool operator==(const box_iterator& o) const;

	bool operator!=(const box_iterator& o) const;

	point2d operator*();

	point2d get_c_pos() const;

	bool is_done() const;

	point2d begin();

protected:

	coord x_beg_;
	coord x_end_;
	coord y_beg_;
	coord y_end_;
	point2d c_pos_;
};

